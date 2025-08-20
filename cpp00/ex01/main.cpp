/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:10:50 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/20 09:58:11 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void	menu(void)
{
	std::cout << "- ADD\t\t[add a contact to your list]" << std::endl;
	std::cout << "- SEARCH\t\t[look for a contact in your list]" << std::endl;
	std::cout << "- EXIT\t\t[exit the program]" << std::endl;
	std::cout << "> ";
}

int	main()
{
	std::string	in;
	int			idx;
	PhoneBook	phoneBook;

	while (1) {
		menu();

		if (!std::getline(std::cin, in, '\n'))
			break ;

		if (in == "ADD") {
			Contact contact = phoneBook.get_contact();
			phoneBook.add(contact);
		} else if (in == "SEARCH") {
			phoneBook.display();
			std::cout << "index: ";
			std::cin >> idx;
			phoneBook.search(idx);
		} else if (in == "EXIT") {
			break ;
		}
		std::cin.ignore();
	}
	return (0);
}
