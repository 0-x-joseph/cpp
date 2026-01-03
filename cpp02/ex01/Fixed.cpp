/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:02:21 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/27 11:07:10 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

const int Fixed::fb = 8;

Fixed::Fixed(void) : fp(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const raw) {
  std::cout << "Int constructor called" << std::endl;
  this->fp = raw << this->fb;
};

Fixed::Fixed(float const raw) {
  std::cout << "Float Constructor called" << std::endl;
  this->fp = roundf(raw * (1 << this->fb));
}

Fixed::Fixed(Fixed const &c) {
  std::cout << "Copy Constructor called" << std::endl;
  *this = c;
}

Fixed &Fixed::operator=(Fixed const &c) {
  std::cout << "Copy assignement operator called" << std::endl;
  if (this != &c)
    this->fp = c.getRawBits();
  return (*this);
}

int Fixed::getRawBits(void) const { return (this->fp); }

int Fixed::setRawBits(int const raw) {
  this->fp = raw;
  return (raw);
}

float Fixed::toFloat(void) const {
  return ((float)this->fp / (float)(1 << this->fb));
}

int Fixed::toInt(void) const { return (this->fp >> this->fb); }

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

std::ostream &operator<<(std::ostream &out, Fixed const &c) {
  out << c.toFloat();
  return (out);
}
