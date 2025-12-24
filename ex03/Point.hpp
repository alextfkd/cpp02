/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:51:54 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/24 05:29:41 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• Private members:
◦ A Fixed const attribute x.
◦ A Fixed const attribute y.
◦ Anything else useful.
• Public members:
◦ A default constructor that initializes x and y to 0.
◦ A constructor that takes two constant floating-point numbers as parameters.
It initializes x and y with those parameters.
◦ A copy constructor.
◦ A copy assignment operator overload.
◦ A destructor.
◦ Anything else useful.
*/

#ifndef POINT_H
#define POINT_H
#include "Fixed.hpp"

class Point {
 private:
  Fixed x_;
  Fixed y_;

 public:
  Point();
  Point(Fixed x, Fixed y);    // NOLINT
  Point(float fx, float fy);  // NOLINT
  Point(const Point& other);
  Point& operator=(const Point& other);
  ~Point();

  void SetX(const Fixed& x);  // NOLINT
  void SetY(const Fixed& y);  // NOLINT

  Fixed GetX() const;
  Fixed GetY() const;

  static Point Vector(const Point& start, const Point& end);
};

bool bsp(Point const a, Point const b, Point const c,  // NOLINT
         Point const point);                           // NOLINT

#endif
