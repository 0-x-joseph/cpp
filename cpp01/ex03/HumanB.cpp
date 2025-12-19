/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:35:17 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/26 16:44:25 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string n) : name(n), weapon(0) {}

void HumanB::attack(void) {
  std::cout << this->name << " attacks with their " << this->weapon->getType()
            << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) { this->weapon = &weapon; }

HumanB::~HumanB(void) { this->weapon = 0x0; }
