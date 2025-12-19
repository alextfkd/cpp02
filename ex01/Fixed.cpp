/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:50:10 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/19 06:33:57 by tkatsuma         ###   ########.fr       */
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
  int int_max       = std::numeric_limits<int>::max();
  int int_min       = std::numeric_limits<int>::min();

  std::cout << "Int constructor called" << std::endl;
  if (num > 0 && (int_max / int_frac_bits) < num) {
    throw std::overflow_error("Error: RawBits excessed INT_MAX");
  }
  if (num < 0 && (int_min / int_frac_bits) > num) {
    throw std::overflow_error("Error: RawBits excessed INT_MIN");
  }
  this->setRawBits(num * int_frac_bits);
}

Fixed::Fixed(const float& num) : value_(0) {
  int int_frac_bits = (1 << Fixed::kNbFractionalBits_);
  int int_max       = std::numeric_limits<int>::max();
  int int_min       = std::numeric_limits<int>::min();

  std::cout << "Float constructor called" << std::endl;
  if (num > 0 && (int_max / int_frac_bits) < int(roundf(num))) {
    throw std::overflow_error("Error: RawBits excessed INT_MAX");
  }
  if (num < 0 && (int_min / int_frac_bits) > int(roundf(num))) {
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

int Fixed::getRawBits(void) const { return (this->value_); }

// sets the raw value of the fixed-point number.
void Fixed::setRawBits(int const raw) { this->value_ = raw; }

std::ostream& operator<<(std::ostream& ostream, const Fixed& other) {
  ostream << other.toFloat();
  return ostream;
}