/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:51:54 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/22 00:00:40 by tkatsuma         ###   ########.fr       */
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

  // Anything else useful.

 public:
  Point();
  Point(Fixed x, Fixed y);
  Point(float fx, float fy);
  Point(const Point& other);
  Point& operator=(const Point& other);
  ~Point();

  void SetX(Fixed x);
  void SetY(Fixed y);

  Fixed GetX() const;
  Fixed GetY() const;

  // Anything else useful.
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
