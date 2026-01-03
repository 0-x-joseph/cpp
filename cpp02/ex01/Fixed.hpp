/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:24:37 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/27 10:57:22 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED__
#define __FIXED__

#include <string>

class Fixed {

public:
  Fixed(void);

  Fixed(int const raw);

  Fixed(float const raw);

  Fixed(Fixed const &raw);

  Fixed &operator=(Fixed const &c);

  float toFloat(void) const;

  int toInt(void) const;

  int getRawBits(void) const;

  int setRawBits(int const raw);

  ~Fixed(void);

private:
  int fp;
  static const int fb;
};

std::ostream &operator<<(std::ostream &out, Fixed const &c);
#endif /* __FIXED__ */
