/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:50:10 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/26 08:51:36 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <limits>
#include <stdexcept>

const float Fixed::kFloatScaleFactor = 256.0F;
const float Fixed::kFloat24Max       = 8388607.0F;
const float Fixed::kFloat24Min       = -8388608.0F;

void Fixed::setMax() {
  this->setRawBits(Fixed::kInt24Max << Fixed::kNbFractionalBits_);
}

void Fixed::setMin() {
  this->setRawBits(Fixed::kInt24Min * (1 << Fixed::kNbFractionalBits_));
}

Fixed::Fixed() : value_(0) {}

Fixed::Fixed(const int& num) : value_(0) {
  if (num < Fixed::kInt24Min) {
    std::cerr << "Error: value < -1 * 2 ^ 23" << std::endl;
    this->setMin();
    return;
  }
  if (num > Fixed::kInt24Max) {
    std::cerr << "Error: value > 2 ^ 23 - 1" << std::endl;
    this->setMax();
    return;
  }
  this->setRawBits(num * (1 << Fixed::kNbFractionalBits_));
}

Fixed::Fixed(const float& num) : value_(0) {
  if (num < Fixed::kFloat24Min) {
    std::cerr << "Error: value < -1 * 2 ^ 23" << std::endl;
    this->setMin();
    return;
  }
  if (num > Fixed::kFloat24Max) {
    std::cerr << "Error: value > 2 ^ 23 - 1" << std::endl;
    this->setMax();
    return;
  }
  this->setRawBits(int(roundf(num * Fixed::kFloatScaleFactor)));
}

Fixed::Fixed(const Fixed& other) { *this = other; }

Fixed& Fixed::operator=(const Fixed& other) {
  if (this != &other) {
    this->value_ = other.getRawBits();
  }
  return *this;
}

Fixed::~Fixed() {}

// converts the fixed-point value to a floating-point value.
float Fixed::toFloat(void) const {
  return (float(this->getRawBits()) / Fixed::kFloatScaleFactor);
}

// converts the fixed-point value to an integer value.
int Fixed::toInt(void) const {
  int res = this->getRawBits();
  res     = (res >> Fixed::kNbFractionalBits_);
  return (res);
}

bool Fixed::operator>(const Fixed& other) const {
  return (this->getRawBits() > other.getRawBits());
}
bool Fixed::operator<(const Fixed& other) const {
  return (this->getRawBits() < other.getRawBits());
}
bool Fixed::operator>=(const Fixed& other) const {
  return (this->getRawBits() >= other.getRawBits());
}
bool Fixed::operator<=(const Fixed& other) const {
  return (this->getRawBits() <= other.getRawBits());
}
bool Fixed::operator==(const Fixed& other) const {
  return (this->getRawBits() == other.getRawBits());
}
bool Fixed::operator!=(const Fixed& other) const {
  return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other) const {
  Fixed res;
  int   thisbits  = this->getRawBits();
  int   otherbits = other.getRawBits();

  if (otherbits > 0 && thisbits > Fixed::kIntMax - otherbits) {
    std::cerr << "Error: Overflow" << std::endl;
    res.setMax();
    return res;
  }
  if (otherbits < 0 && thisbits < Fixed::kIntMin - otherbits) {
    std::cerr << "Error: Underflow" << std::endl;
    res.setMin();
    return res;
  }
  res.setRawBits((this->getRawBits() + other.getRawBits()));
  return res;
}

Fixed Fixed::operator-(const Fixed& other) const {
  Fixed res;
  int   thisbits  = this->getRawBits();
  int   otherbits = other.getRawBits();

  if (otherbits < 0 && thisbits > Fixed::kIntMax + otherbits) {
    std::cerr << "Error: Overflow" << std::endl;
    res.setMax();
    return res;
  }
  if (otherbits > 0 && thisbits < Fixed::kIntMin + otherbits) {
    std::cerr << "Error: Underflow" << std::endl;
    res.setMin();
    return res;
  }
  res.setRawBits((this->getRawBits() - other.getRawBits()));
  return res;
}

Fixed Fixed::operator*(const Fixed& other) const {
  Fixed res;
  int   thisbits  = this->getRawBits();
  int   otherbits = other.getRawBits();
  long  tmp = (long)thisbits * (long)otherbits / (long)Fixed::kIntScaleFactor;

  if (tmp > (long)Fixed::kIntMax) {
    std::cerr << "Error: Overflow" << std::endl;
    res.setMax();
    return res;
  }
  if (tmp < (long)Fixed::kIntMin) {
    std::cerr << "Error: Underflow" << std::endl;
    res.setMin();
    return res;
  }
  res.setRawBits((int)tmp);
  return res;
}

Fixed Fixed::operator/(const Fixed& other) const {
  Fixed res;
  long  tmp;
  int   thisbits  = this->getRawBits();
  int   otherbits = other.getRawBits();

  if (otherbits == 0) {
    std::cerr << "Error: Zero Division" << std::endl;
  }
  tmp = (long)thisbits * (long)Fixed::kIntScaleFactor / (long)otherbits;
  if (tmp > (long)Fixed::kIntMax) {
    std::cerr << "Error: Overflow" << std::endl;
    res.setMax();
    return res;
  }
  if (tmp < (long)Fixed::kIntMin) {
    std::cerr << "Error: Underflow" << std::endl;
    res.setMin();
    return res;
  }
  res.setRawBits((int)tmp);
  return res;
}

Fixed& Fixed::operator++() {
  if (this->getRawBits() == INT_MAX) {
    std::cerr << "Error: Overflow" << std::endl;
    return *this;
  }
  this->setRawBits(this->getRawBits() + 1);
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed res = *this;
  if (this->getRawBits() == INT_MAX) {
    std::cerr << "Error: Overflow" << std::endl;
    return res;
  }
  this->setRawBits(this->getRawBits() + 1);
  return res;
}

Fixed& Fixed::operator--() {
  if (this->getRawBits() == INT_MIN) {
    std::cerr << "Error: Underflow" << std::endl;
    return *this;
  }
  this->setRawBits(this->getRawBits() - 1);
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed res = *this;
  if (this->getRawBits() == INT_MIN) {
    std::cerr << "Error: Underflow" << std::endl;
    return res;
  }
  this->setRawBits(this->getRawBits() - 1);
  return res;
}

int Fixed::getRawBits(void) const { return (this->value_); }

void Fixed::setRawBits(int const raw) { this->value_ = raw; }

std::ostream& operator<<(std::ostream& ostream, const Fixed& other) {
  if (other.getRawBits() % 256 == 0) {  // NOLINT
    ostream << other.toInt();
    return ostream;
  }
  ostream << other.toFloat();
  return ostream;
}

Fixed& Fixed::min(Fixed& left, Fixed& right) {
  if (left > right) {
    return right;
  }
  return left;
}

const Fixed& Fixed::min(const Fixed& left, const Fixed& right) {
  if (left > right) {
    return right;
  }
  return left;
}

Fixed& Fixed::max(Fixed& left, Fixed& right) {
  if (left < right) {
    return right;
  }
  return left;
}

const Fixed& Fixed::max(const Fixed& left, const Fixed& right) {
  if (left < right) {
    return right;
  }
  return left;
}
