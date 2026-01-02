/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:04:51 by ybouryal          #+#    #+#             */
/*   Updated: 2026/01/02 17:42:39 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ScavTrap__
#define __ScavTrap__

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {
protected:
  std::string getType() const;

public:
  ScavTrap();
  ScavTrap(const std::string &name);
  ScavTrap(const ScavTrap &other);
  ScavTrap &operator=(const ScavTrap &other);
  ~ScavTrap();

  void guardGate();
};

#endif /* __ScavTrap__ */
