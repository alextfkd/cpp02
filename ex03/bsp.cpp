/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 00:32:39 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/24 05:30:34 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static Fixed CalcDet(Point& vec0, Point& vec1);
static bool  InverseMatrix(Point arr[2], Point& vec0, Point& vec1);
static Point TransformVector(const Point arr[2], const Point& vec);
static bool  IsInTriangle(const Point& vec);

bool bsp(Point const a, Point const b, Point const c,  // NOLINT
         Point const point) {                          // NOLINT
  Point vab = Point::Vector(a, b);
  Point vac = Point::Vector(a, c);
  Point vap = Point::Vector(a, point);
  Point i_matrix[2];

  if (!InverseMatrix(i_matrix, vab, vac)) {
    return (false);
  }
  Point iap = TransformVector(i_matrix, vap);
  std::cout << "X' = " << iap.GetX() << std::endl;
  std::cout << "Y' = " << iap.GetY() << std::endl;
  return IsInTriangle(iap);
}

static Fixed CalcDet(Point& vec0, Point& vec1) {
  return Fixed(vec0.GetX() * vec1.GetY() - vec0.GetY() * vec1.GetX());
}

static bool InverseMatrix(Point arr[2], Point& vec0, Point& vec1) {
  Fixed det = CalcDet(vec0, vec1);
  if (det == Fixed(0)) {
    return false;
  }
  arr[0] = Point(vec1.GetY(), vec0.GetY() * Fixed(-1));
  arr[1] = Point(vec1.GetX() * Fixed(-1), vec0.GetX());
  arr[0].SetX(arr[0].GetX() / det);
  arr[0].SetY(arr[0].GetY() / det);
  arr[1].SetX(arr[1].GetX() / det);
  arr[1].SetY(arr[1].GetY() / det);
  return true;
}

static Point TransformVector(const Point arr[2], const Point& vec) {
  return Point(arr[0].GetX() * vec.GetX() + arr[1].GetX() * vec.GetY(),
               arr[0].GetY() * vec.GetX() + arr[1].GetY() * vec.GetY());
}

static bool IsInTriangle(const Point& vec) {
  Fixed f_0 = Fixed(0);
  Fixed f_1 = Fixed(1);
  return (vec.GetX() > Fixed(0) && vec.GetX() < Fixed(1) &&
          vec.GetY() > Fixed(0) && vec.GetY() < Fixed(1) &&
          vec.GetX() + vec.GetY() < Fixed(1));
}
