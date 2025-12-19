/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:50:10 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/19 12:41:28 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <limits>
#include <stdexcept>

Fixed::Fixed() : value_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int& num) : value_(0) {
  int int_frac_bits = (1 << Fixed::kNbFractionalBits_);

  std::cout << "Int constructor called" << std::endl;
  if (num > 0 && (Fixed::kIntMax / int_frac_bits) < num) {
    throw std::overflow_error("Error: RawBits excessed INT_MAX");
  }
  if (num < 0 && (Fixed::kIntMin / int_frac_bits) > num) {
    throw std::overflow_error("Error: RawBits excessed INT_MIN");
  }
  this->setRawBits(num * int_frac_bits);
}

Fixed::Fixed(const float& num) : value_(0) {
  int int_frac_bits = (1 << Fixed::kNbFractionalBits_);

  std::cout << "Float constructor called" << std::endl;
  if (num > 0 && (Fixed::kIntMax / int_frac_bits) < int(roundf(num))) {
    throw std::overflow_error("Error: RawBits excessed INT_MAX");
  }
  if (num < 0 && (Fixed::kIntMin / int_frac_bits) > int(roundf(num))) {
    throw std::overflow_error("Error: RawBits excessed INT_MIN");
  }
  this->setRawBits(int(roundf(num * float(int_frac_bits))));
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}
// converts the fixed-point value to a floating-point value.
float Fixed::toFloat(void) const {
  return (float(this->getRawBits()) / (1 << Fixed::kNbFractionalBits_));
}

// converts the fixed-point value to an integer value.
int Fixed::toInt(void) const {
  int res = this->getRawBits();
  res     = (res >> Fixed::kNbFractionalBits_);
  return (res);
}

Fixed& Fixed::operator=(const Fixed& other) {
  std::cout << "Copy assignment operator called" << std::endl;
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

bool Fixed::CheckOverflow(int lvalue, int rvalue) {
  if (lvalue > Fixed::kIntMax - rvalue) {
    return false;
  } else if (lvalue < Fixed::kIntMin + rvalue) {
    return false;
  } else {
    return true;
  }
}

Fixed& Fixed::operator+(const Fixed& other) {
  if (!CheckOverflow(this->getRawBits(), other.getRawBits())) {
    throw std::overflow_error("Overflow Error");
  }
  this->setRawBits((this->getRawBits() + other.getRawBits()));
  return *this;
}

Fixed& Fixed::operator-(const Fixed& other) {
  if (!CheckOverflow(this->getRawBits(), other.getRawBits())) {
    throw std::overflow_error("Overflow Error");
  }
  this->setRawBits((this->getRawBits() - other.getRawBits()));
  return *this;
}

Fixed& Fixed::operator*(const Fixed& other) {
  int int_frac_bits = (1 << Fixed::kNbFractionalBits_);
  if (this->getRawBits() == 0 || other.getRawBits() == 0) {
    this->setRawBits(0);
    return *this;
  }
  if (this->getRawBits() > Fixed::kIntMax / other.getRawBits()) {
    throw std::overflow_error("Overflow Error");
  } else if (this->getRawBits() < Fixed::kIntMin / other.getRawBits()) {
    throw std::overflow_error("Overflow Error");
  } else {
    this->setRawBits(this->getRawBits() * other.getRawBits() / int_frac_bits);
    return *this;
  }
}

Fixed& Fixed::operator/(const Fixed& other) {
  if (other.getRawBits() == 0) {
    throw std::overflow_error("Overflow Error");
  }
  if (this->getRawBits() == 0) {
    this->setRawBits(0);
    return *this;
  }
  if (this->getRawBits() > Fixed::kIntMax * other.getRawBits()) {
    throw std::overflow_error("Overflow Error");
  } else if (this->getRawBits() < Fixed::kIntMin * other.getRawBits()) {
    throw std::overflow_error("Overflow Error");
  } else {
    this->setRawBits(this->getRawBits() / other.getRawBits());
    return *this;
  }
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

// sets the raw value of the fixed-point number.
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