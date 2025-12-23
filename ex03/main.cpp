/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:50:15 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/23 08:24:23 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void) {  // NOLINT
  Point a(Fixed(0), Fixed(0));
  Point b(Fixed(1), Fixed(0));
  Point c(Fixed(0), Fixed(1));
  Point p(Fixed(0.20F), Fixed(0.20F));
  if (bsp(a, b, c, p)) {
    std::cout << "true" << std::endl;
    return 0;
  }
  std::cout << "false" << std::endl;
  return 0;
}
