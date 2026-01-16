/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:50:15 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/01/16 17:21:57 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

int main(void) {
  std::cout << "Subject test start." << std::endl;
  Fixed a;     // NOLINT
  Fixed b(a);  // NOLINT
  Fixed c;     // NOLINT
  c = b;
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
  std::cout << "Subject test finished." << std::endl;
  std::cout << "setRawBits() -> getRawBits() test start." << std::endl;
  std::cout << "Fixed 'a' address: " << &a << std::endl;
  std::cout << "Fixed 'b' address: " << &b << std::endl;
  std::cout << "Fixed 'c' address: " << &c << std::endl;
  a.setRawBits(1);
  b.setRawBits(2);
  c.setRawBits(3);
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
  std::cout << "setRawBits() -> getRawBits() test finished." << std::endl;
  return 0;
}
