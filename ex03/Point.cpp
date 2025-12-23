/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 06:53:33 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/22 00:40:02 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include "Fixed.hpp"

/*
class Point {
 private:
  Fixed x;
  Fixed y;

  // Anything else useful.

 public:
  Point();
  Point(float fx, float fy);
  Point(const Point& other);
  Point& operator=(const Point& other);
  ~Point();

  // Anything else useful.
};
*/

Point::Point() : x_(Fixed()), y_(Fixed()) {}

Point::Point(Fixed x, Fixed y) : x_(x), y_(y) {}

Point::Point(float fx, float fy) : x_(Fixed(fx)), y_(Fixed(fy)) {}

Point::Point(const Point& other) : x_(other.x_), y_(other.y_) {}

Point& Point::operator=(const Point& other) {
  if (this != &other) {
    this->x_ = other.x_;
    this->y_ = other.y_;
  }
  return *this;
}

Point::~Point() {}

Fixed Point::GetX(void) const { return (this->x_); }
Fixed Point::GetY(void) const { return (this->y_); }
void  Point::SetX(Fixed x) { this->x_ = x; }
void  Point::SetY(Fixed y) { this->y_ = y; }
