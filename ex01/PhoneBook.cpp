/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:56:17 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/20 10:19:55 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <iostream>


PhoneBook::PhoneBook(void) {
	this->top = -1;
	this->max_contacts = 9;
	this->column_width = 10;
}

void	PhoneBook::add(Contact contact) {
	if (top == -1) {
		this->contacts[0] = contact;
		this->top = 0;
	} else {
		this->contacts[(top + 1) % this->max_contacts] = contact;
		this->top = (this->top + 1) % this->max_contacts;
	}
}

void	PhoneBook::display(void) {
	this->display_table_header();

	for (int i = 0; i <= this->top; i++)
		this->display_one(i);
}

void	PhoneBook::search(int idx)
{
	if (idx < 0 || idx > this->top)
		return ;
	this->display_table_header();
	this->display_one(idx);
}

Contact	PhoneBook::get_contact(void)
{
	std::string	f, l, n, nbr, s;

	std::cout << "FirstName: ";
	std::cin >> f;
	std::cout << "LastName: ";
	std::cin >> l;
	std::cout << "NickName: ";
	std::cin >> n;
	std::cout << "Phone Number: ";
	std::cin >> nbr;
	std::cout << "Secret: ";
	std::cin >> s;

	return (Contact(f, l, n, nbr, s));
}

void	PhoneBook::display_one(int idx)
{
	int	left;

	std::cout << idx << std::setw(3 + 9) << " | "
		<< Contact::truncate(this->contacts[idx].first_name, this->column_width, left) << std::setw(3 + left) << " | "
		<< Contact::truncate(this->contacts[idx].last_name, this->column_width, left) << std::setw(3 + left) << " | "
		<< Contact::truncate(this->contacts[idx].nickname, this->column_width, left) << std::endl;
	return ;
}

void	PhoneBook::display_table_header()
{
	std::cout << "Index" << std::setw(3 + 5) << " | "
		<< "FirstName" << std::setw(3 + 1) << " | "
		<< "LastName" << std::setw(3 + 2) << " | "
		<< "NickName" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
}
