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
# define __HUMAN_A__

#include <string>
#include "Weapon.hpp"

class HumanA {

public:

	HumanA(void);

	HumanA(std::string name, Weapon& Weapon);

	void attack(void);

	~HumanA(void);

private:
	Weapon*		weapon;
	std::string	name;

};

#endif /* __HUMAN_A__ */
