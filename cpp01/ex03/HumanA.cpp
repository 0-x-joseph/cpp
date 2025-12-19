/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 23:15:03 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/26 16:40:59 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string n, Weapon &w) : name(n), weapon(w) {}

void HumanA::attack(void) {
  std::cout << this->name << " attacks with their " << this->weapon.getType()
            << std::endl;
}

HumanA::~HumanA(void) {}
