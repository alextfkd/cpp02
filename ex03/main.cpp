/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:50:15 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/23 09:14:52 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void) {                        // NOLINT
  Point a(Fixed(0), Fixed(0));          // NOLINT
  Point b(Fixed(1), Fixed(0));          // NOLINT
  Point c(Fixed(0), Fixed(1));          // NOLINT
  Point p(Fixed(0.20F), Fixed(0.20F));  // NOLINT
  if (bsp(a, b, c, p)) {                // NOLINT
    std::cout << "true" << std::endl;   // NOLINT
    return 0;                           // NOLINT
  }  // NOLINT
  std::cout << "false" << std::endl;  // NOLINT
  return 0;                           // NOLINT
}
