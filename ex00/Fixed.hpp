/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:50:12 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/18 16:20:07 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

/*
◦ An integer to store the fixed - point number value.
◦ A static constant integer to store the number of fractional bits.Its value
will always be the integer literal 8.

Default constructor called
Copy constructor called
Copy assignment operator called // <-- This line may be missing depending on
your implementation getRawBits member function called Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called

*/
class Fixed {
 private:
  int              value_;
  static const int kNbFractionalBits_ = 8;

 public:
  Fixed();
  Fixed(const Fixed& other);
  Fixed& operator=(const Fixed& other);
  ~Fixed();

  // returns the raw value of the fixed-point value.
  int getRawBits(void) const;

  // sets the raw value of the fixed-point number.
  void setRawBits(int const raw);  // NOLINT
};

#endif
