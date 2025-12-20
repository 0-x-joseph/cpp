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

class Fixed {
public:
  Fixed(void);

  Fixed(int raw);

  Fixed &operator=(const Fixed &c);

  int getRawBits(void);

  int setRawBits(int const raw);

  ~Fixed(void);

private:
  int fp;
  static const int fb = 8;
};

#endif /* __FIXED__ */
