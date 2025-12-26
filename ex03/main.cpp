/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:50:15 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/26 09:56:44 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

/*
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
*/
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
// ---------------------------------------------------------

void runTest(std::string testName, Point p, Point a, Point b, Point c,
             bool expected) {
  bool        result = bsp(a, b, c, p);
  std::string status = (result == expected) ? "[PASS]" : "[FAIL]";

  std::cout << status << " " << testName << std::endl;
  if (result != expected) {
    std::cout << "  -> Point(" << p.GetX() << ", " << p.GetY()
              << ") Expected: " << (expected ? "True" : "False")
              << ", Got: " << (result ? "True" : "False") << std::endl;
  }
}
int main() {
  // Triangle ABC: Right isosceles triangle at Origin(0,0), (10,0), (0,10)
  Point A = Point(Fixed(0), Fixed(0));
  Point B = Point(Fixed(10), Fixed(0));
  Point C = Point(Fixed(0), Fixed(10));

  std::cout << "=== Basic Cases ===" << std::endl;
  runTest("1. Inside (Center)", Point(3, 3), A, B, C, true);
  runTest("2. Outside (Far)", Point(10, 10), A, B, C, false);
  runTest("3. Outside (Negative coords)", Point(-1, -1), A, B, C, false);
  runTest("4. Outside (Near edge)", Point(5.1f, 5.1f), A, B, C, false);

  std::cout << "\n=== Boundary Cases ===" << std::endl;
  // Assuming 'inside' includes points on edges and vertices.
  runTest("5. On Edge (Bottom)", Point(5, 0), A, B, C, false);
  runTest("6. On Edge (Hypotenuse)", Point(5, 5), A, B, C, false);
  runTest("7. On Vertex (A)", Point(0, 0), A, B, C, false);
  runTest("8. On Vertex (B)", Point(10, 0), A, B, C, false);

  std::cout << "\n=== Variations ===" << std::endl;
  // Triangle with negative coordinates: (-10, -10), (10, -10), (0, 10)
  Point D = Point(Fixed(-10), Fixed(-10));
  Point E = Point(Fixed(10), Fixed(-10));
  Point F = Point(Fixed(0), Fixed(10));

  runTest("9. Inside (Negative Triangle)", Point(0, 0), D, E, F, true);
  runTest("10. Outside (Negative Triangle)", Point(0, -11), D, E, F, false);

  // Check if vertex order matters (Clockwise input)
  runTest("11. Reversed Order (Inside)", Point(3, 3), A, C, B, true);
  runTest("12. Reversed Order (Outside)", Point(10, 10), A, C, B, false);

  // Degenerate triangle (Points on a straight line)
  Point G = Point(Fixed(0), Fixed(0));
  Point H = Point(Fixed(5), Fixed(5));
  Point I = Point(Fixed(10), Fixed(10));
  runTest("13. Straight Line", Point(2, 2), G, H, I, false);

  return 0;
}