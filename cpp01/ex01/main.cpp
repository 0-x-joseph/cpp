/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:15:57 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/24 22:17:33 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main(void) {
	Zombie*	z;

	z = zombieHorde(100, "zz");

	for (int i = 0; i < 100 ; i++)
		z[i].announce();

	delete[] z;
	return (0);
}
