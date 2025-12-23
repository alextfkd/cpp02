/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 00:32:39 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/23 09:02:08 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Point ab = Point(Fixed(b.GetX() - a.GetX()), Fixed(b.GetY() - a.GetY()));
  Point ac = Point(Fixed(c.GetX() - a.GetX()), Fixed(c.GetY() - a.GetY()));
  Point ap =
      Point(Fixed(point.GetX() - a.GetX()), Fixed(point.GetY() - a.GetY()));
  Fixed fixed_0(0);

  std::cout << "[1]" << std::endl;
  Fixed det(ab.GetX() * ac.GetY() - ab.GetY() * ac.GetX());
  if (det == fixed_0) {
    return (false);
  }
  std::cout << "[2]" << std::endl;
  std::cout << ab.GetX() * Fixed(-1) << std::endl;
  Point arr[2] = {Point(ac.GetY(), ab.GetY() * Fixed(-1)),
                  Point(ac.GetX() * Fixed(-1), ab.GetX())};
  std::cout << "[3]" << std::endl;
  arr[0].SetX(arr[0].GetX() / det);
  arr[0].SetY(arr[0].GetY() / det);
  arr[1].SetX(arr[1].GetX() / det);
  arr[1].SetY(arr[1].GetY() / det);
  std::cout << "[4]" << std::endl;
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
