/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:35:59 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/26 16:44:59 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMAN_B__
# define __HUMAN_B__

# include <string>
# include "Weapon.hpp"

class HumanB {

public:

	HumanB(void);

	HumanB(std::string name);

	HumanB(std::string name, Weapon& weapon);

	void setWeapon(Weapon& weapon);

	void attack(void);

	~HumanB(void);

private:
	Weapon*		weapon;
	std::string	name;

};

#endif /* __HUMAN_B__ */
