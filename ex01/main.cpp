/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:10:50 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/19 12:11:51 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main()
{
	std::string	in;
	PhoneBook	phoneBook;
	Contact		contact;

	while (1) {
		std::getline(std::cin, in, '\n');
		std::cout << in;
		if (in == "ADD") {
			phoneBook.add(contact);
		} else if (in == "SEARCH") {
			phoneBook.display();
			phoneBook.search(contact);
		} else if (in == "EXIT") {
			break ;
		} else
			phoneBook.display();
	}
	return (0);
}
