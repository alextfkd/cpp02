/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:50:12 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/26 15:49:15 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <climits>
#include <cmath>
#include <iostream>

/*
Add public member functions to your class to overload the following operators:
• The 6 comparison operators: >, <, >=, <=, ==, and !=.
• The 4 arithmetic operators: +, -, *, and /.
• The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
post-decrement) operators, which will increase or decrease the fixed-point value
by the smallest representable ϵ, such that 1 + ϵ > 1

Add these four public overloaded member functions to your class:

• A static member function min that takes two references to fixed-point numbers
as parameters, and returns a reference to the smallest one.

• A static member function min that takes two references to constant fixed-point
numbers as parameters, and returns a reference to the smallest one.

• A static member function max that takes two references to fixed-point numbers
as parameters, and returns a reference to the greatest one.

• A static member function max that takes two references to constant fixed-point
numbers as parameters, and returns a reference to the greatest one.

*/
class Fixed {
 private:
  int              value_;
  static const int kNbFractionalBits_ = 8;
  static const int kIntScaleFactor    = 256;
  static const int kInt24Max          = 8388607;
  static const int kInt24Min          = -8388608;
  static const int kIntMax            = INT_MAX;
  static const int kIntMin            = INT_MIN;

  static const float kFloatScaleFactor;
  static const float kFloat24Max;
  static const float kFloat24Min;

 public:
  Fixed();
  Fixed(const int& num);
  Fixed(const float& num);
  Fixed(const Fixed& other);

  Fixed& operator=(const Fixed& other);

  Fixed operator+(const Fixed& other) const;
  Fixed operator-(const Fixed& other) const;
  Fixed operator*(const Fixed& other) const;
  Fixed operator/(const Fixed& other) const;

  bool operator>(const Fixed& other) const;
  bool operator<(const Fixed& other) const;
  bool operator>=(const Fixed& other) const;
  bool operator<=(const Fixed& other) const;
  bool operator==(const Fixed& other) const;
  bool operator!=(const Fixed& other) const;

  Fixed& operator++();
  Fixed  operator++(int);
  Fixed& operator--();
  Fixed  operator--(int);

  static Fixed&       min(Fixed& left, Fixed& right);
  const static Fixed& min(const Fixed& left, const Fixed& right);
  static Fixed&       max(Fixed& left, Fixed& right);
  const static Fixed& max(const Fixed& left, const Fixed& right);

  ~Fixed();

  // converts the fixed-point value to a floating-point value.
  float toFloat(void) const;
  // converts the fixed-point value to an integer value.
  int toInt(void) const;

  // returns the raw value of the fixed-point value.
  int getRawBits(void) const;

  // sets the raw value of the fixed-point number.
  void setRawBits(int const raw);  // NOLINT
  void setMax();
  void setMin();
};

std::ostream& operator<<(std::ostream& ostream, const Fixed& other);

#endif
