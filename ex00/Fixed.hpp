/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:50:12 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/24 05:39:08 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

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
