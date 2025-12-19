/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:55:15 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/24 22:57:53 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON__
#define __WEAPON__

#include <string>

class Weapon {

public:
  Weapon(void);

  Weapon(std::string t);

  const std::string &getType(void) const;

  void setType(std::string t);

  ~Weapon(void);

private:
  std::string type;
};

#endif /* __WEAPON__ */
