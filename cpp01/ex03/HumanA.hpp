/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 23:14:54 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/26 16:39:42 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMAN_A__
#define __HUMAN_A__

#include "Weapon.hpp"
#include <string>

class HumanA {

public:
  HumanA(std::string n, Weapon &w);

  void attack(void);

  ~HumanA(void);

private:
  std::string name;
  Weapon &weapon;
};

#endif /* __HUMAN_A__ */
