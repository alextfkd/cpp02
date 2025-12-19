/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:50:15 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/19 04:31:13 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
// *

int main(void) {
  Fixed       a;                                                    // NOLINT
  Fixed const b(10);                                                // NOLINT
  Fixed const c(42.42f);                                            // NOLINT
  Fixed const d(b);                                                 // NOLINT
  a = Fixed(1234.4321f);                                            // NOLINT
  std::cout << "a is " << a << std::endl;                           // NOLINT
  std::cout << "b is " << b << std::endl;                           // NOLINT
  std::cout << "c is " << c << std::endl;                           // NOLINT
  std::cout << "d is " << d << std::endl;                           // NOLINT
  std::cout << "a is " << a.toInt() << " as integer" << std::endl;  // NOLINT
  std::cout << "b is " << b.toInt() << " as integer" << std::endl;  // NOLINT
  std::cout << "c is " << c.toInt() << " as integer" << std::endl;  // NOLINT
  std::cout << "d is " << d.toInt() << " as integer" << std::endl;  // NOLINT
  return 0;
}