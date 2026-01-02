/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:07:19 by ybouryal          #+#    #+#             */
/*   Updated: 2026/01/02 16:41:22 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap()
    : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
  std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {

  std::cout << "ClapTrap constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
  *this = other;
  std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  if (this != &other) {
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
  }
  std::cout << "ClapTrap copy assignement operator called" << std::endl;
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap destructor called for " << name << std::endl;
}

void ClapTrap::attack(const std::string &target) {
  if (hitPoints <= 0) {
    std::cout << "ClapTrap " << name << " is dead and can't attack!\n";
    return;
  }
  if (energyPoints <= 0) {
    std::cout << "ClapTrap " << name << " has no energy left!\n";
    return;
  }
  energyPoints--;
  std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
            << attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
  hitPoints -= amount;
  if (hitPoints < 0) {
    hitPoints = 0;
  }
  std::cout << "ClapTrap " << name << " takes " << amount
            << " points of damage! "
            << "HP left: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (hitPoints <= 0) {
    std::cout << "ClapTrap " << name << " is dead and can't be repaired!\n";
    return;
  }
  if (energyPoints <= 0) {
    std::cout << "ClapTrap " << name << " has no energy left!\n";
    return;
  }
  energyPoints--;
  hitPoints += amount;
  std::cout << "ClapTrap " << name << " repairs itself for " << amount
            << " hit points! "
            << "HP now: " << hitPoints << std::endl;
}
