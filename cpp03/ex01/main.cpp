/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:42:54 by ybouryal          #+#    #+#             */
/*   Updated: 2026/01/02 17:59:52 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  ClapTrap a("Hamid");
  ScavTrap b("Allal");

  a.attack("Allal");
  b.takeDamage(5);

  b.attack("Hamid");
  a.takeDamage(20);

  b.guardGate();

  return 0;
}
