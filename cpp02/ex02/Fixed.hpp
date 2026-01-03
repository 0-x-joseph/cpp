/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:10:48 by ybouryal          #+#    #+#             */
/*   Updated: 2025/12/20 11:10:49 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED__
#define __FIXED__

#include <iostream>
#include <string>

class Fixed {

public:
  // Overloading Constructors for different type we support
  Fixed(void);
  Fixed(int const raw);
  Fixed(float const raw);
  Fixed(Fixed const &raw);

  // Overloading Copy assignement operator
  Fixed &operator=(Fixed const &c);

  // Overloading Comparison Operators
  bool operator>(const Fixed &ob) const;
  bool operator<(const Fixed &ob) const;
  bool operator>=(const Fixed &ob) const;
  bool operator<=(const Fixed &ob) const;
  bool operator==(const Fixed &ob) const;
  bool operator!=(const Fixed &ob) const;

  // Overloading Arithmetic Operators
  float operator+(const Fixed &ob) const;
  float operator-(const Fixed &ob) const;
  float operator*(const Fixed &ob) const;
  float operator/(const Fixed &ob) const;

  // Overloading Inc/Dec Operators
  Fixed operator++();
  Fixed operator++(int);
  Fixed operator--();
  Fixed operator--(int);

  // Overloading min max
  static Fixed &min(Fixed &ob1, Fixed &ob2);
  static const Fixed &min(const Fixed &ob1, const Fixed &ob2);
  static Fixed &max(Fixed &ob1, Fixed &ob2);
  static const Fixed &max(const Fixed &ob1, const Fixed &ob2);

  // Utility function for the class
  float toFloat(void) const;
  int toInt(void) const;
  int getRawBits(void) const;
  int setRawBits(int const raw);

  // Destructor
  ~Fixed(void);

private:
  int fp;
  static const int fb;
};

std::ostream &operator<<(std::ostream &out, Fixed const &c);
#endif /* __FIXED__ */
