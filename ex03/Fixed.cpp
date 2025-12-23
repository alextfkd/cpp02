/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:50:10 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/23 08:03:32 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <limits>
#include <stdexcept>

const float Fixed::kFloatScaleFactor = 256.0F;
const float Fixed::kFloat24Max       = 8388607.0F;
const float Fixed::kFloat24Min       = -8388608.0F;

Fixed::Fixed() : value_(0) {}

Fixed::Fixed(const int& num) : value_(0) {
  if (num < Fixed::kInt24Min) {
    std::cerr << "Error: value < -1 * 2 ^ 23" << std::endl;
  } else if (num > Fixed::kInt24Max) {
    std::cerr << "Error: value > 2 ^ 23 - 1" << std::endl;
  }
  this->setRawBits(num << Fixed::kNbFractionalBits_);
}

Fixed::Fixed(const float& num) : value_(0) {
  if (num < Fixed::kFloat24Min) {
    std::cerr << "Error: value < -1 * 2 ^ 23" << std::endl;
  } else if (num > Fixed::kFloat24Max) {
    std::cerr << "Error: value > 2 ^ 23 - 1" << std::endl;
  }
  this->setRawBits(int(roundf(num * Fixed::kFloatScaleFactor)));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& other) { *this = other; }

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

Fixed& Fixed::operator=(const Fixed& other) {
  if (this != &other) {
    this->value_ = other.getRawBits();
  }
  return *this;
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
  int thisbits  = this->getRawBits();
  int otherbits = other.getRawBits();
  if (otherbits > 0 && thisbits > Fixed::kIntMax - otherbits) {
    std::cerr << "Error: Overflow" << std::endl;
  }
  if (otherbits < 0 && thisbits < Fixed::kIntMin - otherbits) {
    std::cerr << "Error: Underflow" << std::endl;
  }
  Fixed res;
  res.setRawBits((this->getRawBits() + other.getRawBits()));
  return res;
}

Fixed Fixed::operator-(const Fixed& other) const {
  int thisbits  = this->getRawBits();
  int otherbits = other.getRawBits();
  if (otherbits < 0 && thisbits > Fixed::kIntMax + otherbits) {
    std::cerr << "Error: Overflow" << std::endl;
  }
  if (otherbits > 0 && thisbits < Fixed::kIntMin + otherbits) {
    std::cerr << "Error: Underflow" << std::endl;
  }
  Fixed res;
  res.setRawBits((this->getRawBits() - other.getRawBits()));
  return res;
}

Fixed Fixed::operator*(const Fixed& other) const {
  int  thisbits  = this->getRawBits();
  int  otherbits = other.getRawBits();
  long tmp = (long)thisbits * (long)otherbits / (long)Fixed::kIntScaleFactor;

  if (tmp > (long)Fixed::kIntMax) {
    std::cerr << "Error: Overflow" << std::endl;
  }
  if (tmp < (long)Fixed::kIntMin) {
    std::cerr << "Error: Underflow" << std::endl;
  }
  Fixed res;
  res.setRawBits((int)tmp);
  return res;
}

Fixed Fixed::operator/(const Fixed& other) const {
  int   thisbits  = this->getRawBits();
  int   otherbits = other.getRawBits();
  Fixed res;
  if (otherbits == 0) {
    std::cerr << "Error: Zero Division" << std::endl;
  }
  long tmp = (long)thisbits * (long)Fixed::kIntScaleFactor / (long)otherbits;

  if (tmp > (long)Fixed::kIntMax) {
    std::cerr << "Error: Overflow" << std::endl;
  }
  if (tmp < (long)Fixed::kIntMin) {
    std::cerr << "Error: Underflow" << std::endl;
  }
  res.setRawBits((int)tmp);
  return res;
}

Fixed& Fixed::operator++() {
  this->setRawBits(this->getRawBits() + 1);
  return *this;
}
Fixed Fixed::operator++(int) {
  Fixed res = *this;
  this->setRawBits(this->getRawBits() + 1);
  return res;
}
Fixed& Fixed::operator--() {
  this->setRawBits(this->getRawBits() - 1);
  return *this;
}
Fixed Fixed::operator--(int) {
  Fixed res = *this;
  this->setRawBits(this->getRawBits() - 1);
  return res;
}

int Fixed::getRawBits(void) const { return (this->value_); }

void Fixed::setRawBits(int const raw) { this->value_ = raw; }

std::ostream& operator<<(std::ostream& ostream, const Fixed& other) {
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
