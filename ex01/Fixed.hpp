/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:50:12 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/26 15:48:57 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <cmath>
#include <iostream>

/*
Add the following public constructors and public member functions to your class:
• A constructor that takes a constant integer as a parameter.
It converts it to the corresponding fixed-point value. The fractional bits value
should be initialized to 8, like in exercise 00.
• A constructor that takes a constant floating-point number as a parameter.
It converts it to the corresponding fixed-point value. The fractional bits value
should be initialized to 8, like in exercise 00.
• A member function float toFloat( void ) const;
that converts the fixed-point value to a floating-point value.
• A member function int toInt( void ) const;
that converts the fixed-point value to an integer value.
*/
class Fixed {
 private:
  int              value_;
  static const int kNbFractionalBits_ = 8;

 public:
  Fixed();

  Fixed(const int& num);

  Fixed(const float& num);

  Fixed(const Fixed& other);

  Fixed& operator=(const Fixed& other);

  ~Fixed();

  // converts the fixed-point value to a floating-point value.
  float toFloat(void) const;
  // converts the fixed-point value to an integer value.
  int toInt(void) const;

  // returns the raw value of the fixed-point value.
  int getRawBits(void) const;

  // sets the raw value of the fixed-point number.
  void setRawBits(int const raw);  // NOLINT
};

std::ostream& operator<<(std::ostream& ostream, const Fixed& other);

#endif
