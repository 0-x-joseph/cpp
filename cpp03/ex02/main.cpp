/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:55:30 by ybouryal          #+#    #+#             */
/*   Updated: 2026/01/02 18:55:35 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main() {
  FragTrap frag("Hamid");

  frag.attack("Abd Lkader");
  frag.takeDamage(50);
  frag.beRepaired(20);
  frag.highFivesGuys();

  FragTrap fragCopy(frag);
  fragCopy.highFivesGuys();

  return 0;
}
