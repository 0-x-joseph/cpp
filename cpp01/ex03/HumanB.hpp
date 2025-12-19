/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:35:59 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/26 16:44:59 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMAN_B__
#define __HUMAN_B__

#include "Weapon.hpp"
#include <string>

class HumanB {

public:
  HumanB(std::string n);

  void setWeapon(Weapon &w);

  void attack(void);

  ~HumanB(void);

private:
  std::string name;
  Weapon *weapon;
};

#endif /* __HUMAN_B__ */
