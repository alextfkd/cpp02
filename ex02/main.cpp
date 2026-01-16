/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:50:15 by tkatsuma          #+#    #+#             */
/*   Updated: 2026/01/16 18:41:54 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int overflow_test(void){
  std::cout << "\nOverflow / Underflow tests\n" << std::endl;

  std::cout << "Reset c to Fixed(0)" << std::endl;
  Fixed c = Fixed(0);
  std::cout << "c: " << c << std::endl;

  std::cout << "Subtracting 2 ^ 23 - 1 from c" << std::endl;
  c = c - Fixed(8388607);
  std::cout << "c: " << c << std::endl;
  std::cout << "c = c - Fixed(1);" << std::endl;
  c = c - Fixed(1);
  std::cout << "c: " << c << std::endl;
  std::cout << "c = c - Fixed(1);" << std::endl;
  c = c - Fixed(1);
  std::cout << "c: " << c << std::endl;
  std::cout << std::endl;

  std::cout << "c: " << Fixed(10000) * Fixed(10000) << std::endl;
  std::cout << "c: " << Fixed(-10000) * Fixed(10000) << std::endl;
  std::cout << "c: " << Fixed(-10000) * Fixed(-10000) << std::endl;
  std::cout << "c: " << Fixed(8388607) / Fixed(0.01f) << std::endl;
  std::cout << "c: " << Fixed(8388607) / Fixed(-0.01f) << std::endl;
  return 0;
}

int main(void) {
  Fixed       a;
  Fixed const b(Fixed(5.05f) * Fixed(-1));
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;

  Fixed c_dash(0);
  Fixed c = c_dash;
  std::cout << "Using copy assignment constructor, expecting c as 0"
            << std::endl;
  std::cout << "c: " << c << std::endl;

  std::cout << "\nOverflow tests\n" << std::endl;

  std::cout << "Reset c to Fixed(0)" << std::endl;
  c = Fixed(0);
  std::cout << "c: " << c << std::endl;

  std::cout << "Adding 2 ^ 23 - 1 to c" << std::endl;
  c = c + Fixed(8388608 - 1);
  std::cout << "c: " << c << std::endl;
  std::cout << "c = c + Fixed(1);" << std::endl;
  c = c + Fixed(1);
  std::cout << "c: " << c << std::endl;
  overflow_test();
  return 0;
}
