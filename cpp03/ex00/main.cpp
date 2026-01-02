/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:42:54 by ybouryal          #+#    #+#             */
/*   Updated: 2026/01/02 16:42:56 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
  ClapTrap a("Alpha");
  ClapTrap b("Beta");

  a.attack("Beta");
  b.takeDamage(0);

  b.attack("Alpha");
  a.takeDamage(5);

  a.beRepaired(3);
  a.attack("Beta");
}
