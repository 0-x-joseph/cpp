/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:46:49 by ybouryal          #+#    #+#             */
/*   Updated: 2026/01/02 18:54:54 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("FragTrap") {
  hitPoints = 100;
  energyPoints = 100;
  attackDamage = 30;
  std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &n) : ClapTrap(n) {
  hitPoints = 100;
  energyPoints = 100;
  attackDamage = 30;
  std::cout << "FragTrap constructor called for " << n << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  hitPoints = 100;
  energyPoints = 100;
  attackDamage = 30;
  std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  std::cout << "FragTrap copy assignement operator called" << std::endl;
  ClapTrap::operator=(other);
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor called for " << name << std::endl;
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << name << " says: \"High five, anyone? ✋\""
            << std::endl;
}

std::string FragTrap::getType() const { return "FragTrap"; }
