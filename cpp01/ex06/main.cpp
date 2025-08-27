/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 08:58:44 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/27 08:58:49 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

unsigned simple_hash(const std::string &s) {
    unsigned h = 0;
    for (size_t i = 0; i < s.size(); ++i)
        h = h * 31 + s[i];
    return h;
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);

	std::string level = av[1];
    Harl harl;
	switch (simple_hash(level)) {
		case 0x3de9e33:
			harl.complain("DEBUG");
			std::cout << std::endl;
	
		case 0x225cae:
			harl.complain("INFO");
			std::cout << std::endl;
		case 0x6dd13b7c:
			harl.complain("WARNING");
			std::cout << std::endl;
		case 0x3f2d9e8:
			harl.complain("ERROR");
			break ;
		default:
			harl.complain(level);
	}
    return 0;
}
