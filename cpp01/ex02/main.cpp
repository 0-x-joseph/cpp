/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:45:17 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/24 22:48:24 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <string>
#include <iostream>

int	main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string& str_ref = str;
	std::string* str_ptr = &str;

	std::cout << "string address    : " << &str << std::endl;
	std::cout << "string ptr address: " << str_ptr << std::endl;
	std::cout << "string ref address: " << &str_ref << std::endl;

	std::cout << std::endl;

	std::cout << "string content    : " << str << std::endl;
	std::cout << "string ptr content: " << *str_ptr << std::endl;
	std::cout << "string ref content: " << str_ref << std::endl;

	return (0);
}
