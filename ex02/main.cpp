/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:50:15 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/26 08:52:35 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {                               // NOLINT
  Fixed       a;                               // NOLINT
  Fixed const b(Fixed(5.05f) * Fixed(-1));     // NOLINT
  std::cout << a << std::endl;                 // NOLINT
  std::cout << ++a << std::endl;               // NOLINT
  std::cout << a << std::endl;                 // NOLINT
  std::cout << a++ << std::endl;               // NOLINT
  std::cout << a << std::endl;                 // NOLINT
  std::cout << b << std::endl;                 // NOLINT
  std::cout << Fixed::max(a, b) << std::endl;  // NOLINT

  Fixed c_dash(0);
  Fixed c = c_dash;                                                   // NOLINT
  std::cout << "Using copy assignment constructor, expecting c as 0"  // NOLINT
            << std::endl;                                             // NOLINT
  std::cout << "c: " << c << std::endl;                               // NOLINT
  std::cout << "Adding 2 ^ 23 - 1 to c" << std::endl;                 // NOLINT
  c = c + Fixed(8388608 - 1);                                         // NOLINT
  std::cout << "c: " << c << std::endl;                               // NOLINT
  std::cout << "Adding 1 to c will cause overflow. " << std::endl;    // NOLINT
  c = c + Fixed(1);                                                   // NOLINT
  std::cout << "c: " << c << std::endl;                               // NOLINT
  std::cout << std::endl;                                             // NOLINT
  return 0;
}
