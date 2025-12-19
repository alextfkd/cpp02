/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:50:15 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/19 06:57:55 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {                               // NOLINT
  Fixed       a;                               // NOLINT
  Fixed const b(Fixed(5.05f) * Fixed(2));      // NOLINT
  std::cout << a << std::endl;                 // NOLINT
  std::cout << ++a << std::endl;               // NOLINT
  std::cout << a << std::endl;                 // NOLINT
  std::cout << a++ << std::endl;               // NOLINT
  std::cout << a << std::endl;                 // NOLINT
  std::cout << b << std::endl;                 // NOLINT
  std::cout << Fixed::max(a, b) << std::endl;  // NOLINT
  return 0;
}