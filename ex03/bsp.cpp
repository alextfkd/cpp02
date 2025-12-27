/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 00:32:39 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/27 10:35:56 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static Fixed calcDet(Point& vec0, Point& vec1);
static Fixed threePointDet(const Point& origin, const Point& right,
                           const Point& point);
static bool  isInTriangle(const Fixed& det_a, const Fixed& det_b,
                          const Fixed& det_c);

bool bsp(Point const a, Point const b, Point const c,  // NOLINT
         Point const point) {                          // NOLINT
  Fixed det_a = threePointDet(a, b, point);
  Fixed det_b = threePointDet(b, c, point);
  Fixed det_c = threePointDet(c, a, point);
  return isInTriangle(det_a, det_b, det_c);
}

static Fixed calcDet(Point& vec0, Point& vec1) {
  return Fixed(vec0.GetX() * vec1.GetY() - vec0.GetY() * vec1.GetX());
}

static Fixed threePointDet(const Point& origin, const Point& right,
                           const Point& point) {
  Point vop = Point::Vector(origin, point);
  Point vor = Point::Vector(origin, right);
  return calcDet(vop, vor);
}

static bool isInTriangle(const Fixed& det_a, const Fixed& det_b,
                         const Fixed& det_c) {
  if (det_a == Fixed(0) || det_b == Fixed(0) || det_c == Fixed(0)) {
    return false;
  }
  if (det_a > Fixed(0) && det_b > Fixed(0) && det_c > Fixed(0)) {
    return true;
  }
  if (det_a < Fixed(0) && det_b < Fixed(0) && det_c < Fixed(0)) {
    return true;
  }
  return false;
}
