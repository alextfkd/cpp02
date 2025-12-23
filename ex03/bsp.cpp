/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 00:32:39 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/23 09:53:53 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Fixed det(Point& vector0, Point& vector1) {
  Fixed res =
      Fixed(vector0.GetX() * vector1.GetY() - vector0.GetY() * vector1.GetX());
  return res;
}

bool InverseMatrix(Point arr[2], Point& vector0, Point& vector1) {
  Fixed abac_det = det(vector0, vector1);
  if (abac_det == Fixed(0)) {
    return false;
  }
  arr[0] = Point(vector1.GetY(), vector0.GetY() * Fixed(-1));
  arr[1] = Point(vector1.GetX() * Fixed(-1), vector0.GetX());
  arr[0].SetX(arr[0].GetX() / abac_det);
  arr[0].SetY(arr[0].GetY() / abac_det);
  arr[1].SetX(arr[1].GetX() / abac_det);
  arr[1].SetY(arr[1].GetY() / abac_det);
  return true;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Point ab = Point(Fixed(b.GetX() - a.GetX()), Fixed(b.GetY() - a.GetY()));
  Point ac = Point(Fixed(c.GetX() - a.GetX()), Fixed(c.GetY() - a.GetY()));
  Point ap =
      Point(Fixed(point.GetX() - a.GetX()), Fixed(point.GetY() - a.GetY()));
  Fixed fixed_0(0);
  Point arr[2];

  if (!InverseMatrix(arr, ab, ac)) {
    return (false);
  }

  Point iap(arr[0].GetX() * ap.GetX() + arr[1].GetX() * ap.GetY(),
            arr[0].GetY() * ap.GetX() + arr[1].GetY() * ap.GetY());
  std::cout << "X' = " << iap.GetX() << std::endl;
  std::cout << "Y' = " << iap.GetY() << std::endl;

  if (iap.GetX() > Fixed(0) && iap.GetX() < Fixed(1) && iap.GetY() > Fixed(0) &&
      iap.GetY() < Fixed(1) && iap.GetX() + iap.GetY() < Fixed(1)) {
    return true;
  }
  return false;
}
