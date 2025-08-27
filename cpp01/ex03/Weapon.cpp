/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 23:00:18 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/24 23:02:24 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon(void) {}

Weapon::Weapon(std::string type) { this->type = type; }

const std::string& Weapon::getType(void) const {
	return (this->type);
}

void	Weapon::setType( std::string t ) {
	this->type = t;
}

Weapon::~Weapon( void ) {}
