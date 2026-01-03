/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:10:54 by ybouryal          #+#    #+#             */
/*   Updated: 2025/12/20 11:11:18 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int32_t Fixed::fb = 8;

Fixed::Fixed(void) : fp(0) {}

Fixed::Fixed(const int raw) { fp = raw << fb; }

Fixed::Fixed(const float raw) : fp(roundf(raw * (1 << fb))) {
  fp = roundf(raw * (1 << fb));
}

Fixed::Fixed(const Fixed &copy) { *this = copy; }

// Overloading Copy assignement operator
Fixed &Fixed::operator=(Fixed const &c) {
  if (&c != this) {
    fp = c.getRawBits();
  }
  return *this;
}

// Overloading Comparison Operators
bool Fixed::operator>(const Fixed &ob) const {
  return (this->toFloat() > ob.toFloat());
}

bool Fixed::operator<(const Fixed &ob) const { return (ob > *this); }

bool Fixed::operator>=(const Fixed &ob) const { return !(ob < *this); }

bool Fixed::operator<=(const Fixed &ob) const { return !(*this < ob); }

bool Fixed::operator==(const Fixed &ob) const {
  return (this->toFloat() == ob.toFloat());
}

bool Fixed::operator!=(const Fixed &ob) const {
  return (this->toFloat() != ob.toFloat());
}

// Overloading Arithmetic Operators
float Fixed::operator+(const Fixed &ob) const {
  return this->toFloat() + ob.toFloat();
}

float Fixed::operator-(const Fixed &ob) const {
  return this->toFloat() - ob.toFloat();
}

float Fixed::operator*(const Fixed &ob) const {
  return this->toFloat() * ob.toFloat();
}

float Fixed::operator/(const Fixed &ob) const {
  return this->toFloat() / ob.toFloat();
}

// Overloading Inc/Dec Operators
Fixed Fixed::operator++() {
  fp++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed old = *this;

  ++fp;
  return old;
}

Fixed Fixed::operator--() {
  fp--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed old = *this;

  --fp;
  return old;
}

// Overloading min max
Fixed &Fixed::min(Fixed &ob1, Fixed &ob2) {
  if (ob1.toFloat() <= ob2.toFloat())
    return ob1;
  return ob2;
}
const Fixed &Fixed::min(const Fixed &ob1, const Fixed &ob2) {
  if (ob1.toFloat() <= ob2.toFloat())
    return ob1;
  return ob2;
}

Fixed &Fixed::max(Fixed &ob1, Fixed &ob2) {
  if (ob1.toFloat() >= ob2.toFloat())
    return ob1;
  return ob2;
}

const Fixed &Fixed::max(const Fixed &ob1, const Fixed &ob2) {
  if (ob1.toFloat() >= ob2.toFloat())
    return ob1;
  return ob2;
}

// Utility function for the class
float Fixed::toFloat(void) const { return ((float)fp / (float)(1 << fb)); }

int Fixed::toInt(void) const { return (fp >> fb); }

int Fixed::getRawBits(void) const { return fp; }

int Fixed::setRawBits(int const raw) {
  fp = raw;
  return fp;
}

// Destructor
Fixed::~Fixed(void) {}

std::ostream &operator<<(std::ostream &out, const Fixed &c) {
  out << c.toFloat();
  return (out);
}
