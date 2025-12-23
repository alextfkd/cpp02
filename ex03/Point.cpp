/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 06:53:33 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/23 09:22:58 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include "Fixed.hpp"

Point::Point() : x_(0), y_(0) {}

Point::Point(Fixed x, Fixed y) : x_(x), y_(y) {}  // NOLINT

Point::Point(float fx, float fy) : x_(Fixed(fx)), y_(Fixed(fy)) {}  // NOLINT

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
void  Point::SetX(const Fixed& x) { this->x_ = x; }  // NOLINT
void  Point::SetY(const Fixed& y) { this->y_ = y; }  // NOLINT
