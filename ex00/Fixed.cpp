/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:50:10 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/18 16:19:22 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  this->value_ = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->value_ = other.getRawBits();
  }
  return *this;
}
int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return (this->value_);
}

// sets the raw value of the fixed-point number.
void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->value_ = raw;
}