/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:56:17 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/22 18:49:19 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <string>


PhoneBook::PhoneBook(void) {
	this->top = -1;
	this->max_contacts = 8;
	this->column_width = 10;
	this->len = -1;
}

void	PhoneBook::add(Contact contact) {
	if (top == -1) {
		this->contacts[0] = contact;
		this->top = 0;
		this->len++;
	} else if (this->top == this->max_contacts - 1) {
		this->top = -1;
		this->contacts[++this->top] = contact;
	} else {
		this->contacts[++this->top] = contact;
		if (this->len < this->max_contacts - 1)
			this->len++;
	}
}

void	PhoneBook::display(void)
{
	int	i;

	this->display_table_header();

	for (i = 0; i <= this->len; i++)
		this->display_one(i);

	if (i == 0) {
		std::cout << "Empty" << std::setw(45) << "|" << std::endl;
		std::cout << "--------------------------------------------------" << std::endl;
	}
}

void	PhoneBook::search(void)
{
	int	idx;
	while (1)
	{
		std::cout << "index (0-7): ";
		std::cin >> idx;
		if (std::cin.eof())
			return ;
		if (std::cin.fail() || idx < 0 || idx >= this->max_contacts) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please provide an index between 0 and 7" << std::endl;
			continue ;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break ;
	}
	this->display_table_header();
	if (idx > this->len) {
		std::cout << "Empty" << std::setw(45) << "|" << std::endl;
		std::cout << "--------------------------------------------------" << std::endl;
		return ;
	}
	this->display_one(idx);
}

Contact	PhoneBook::get_contact(void)
{
	std::string	f, l, n, nbr, s;

	f = PhoneBook::get_info((char *)"Firstname");
	if (f.empty())
		return Contact();
	l = PhoneBook::get_info((char *)"Lastname");
	if (l.empty())
		return Contact();
	n = PhoneBook::get_info((char *)"Nickname");
	if (n.empty())
		return Contact();
	nbr = PhoneBook::get_info((char *)"Phone Number");
	if (nbr.empty())
		return Contact();
	s = PhoneBook::get_info((char *)"Secret");
	if (s.empty())
		return Contact();
	return (Contact(f, l, n, nbr, s));
}

void	PhoneBook::display_one(int idx)
{
	int	left;

	std::cout << idx << std::setw(3 + 9) << " | "
		<< Contact::truncate(this->contacts[idx].first_name, this->column_width, left)
		<< std::setw(3 + left) << " | "
		<< Contact::truncate(this->contacts[idx].last_name, this->column_width, left)
		<< std::setw(3 + left) << " | "
		<< Contact::truncate(this->contacts[idx].nickname, this->column_width, left)
		<< std::setw(1 + left) << "|" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	return ;
}

void	PhoneBook::display_table_header()
{
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Index" << std::setw(3 + 5) << " | "
		<< "FirstName" << std::setw(3 + 1) << " | "
		<< "LastName" << std::setw(3 + 2) << " | "
		<< "NickName" << std::setw(1 + 2) << "|" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
}

std::string	PhoneBook::get_info(char *name)
{
	std::string	value;
	std::cout << name << " > ";
	while (1) {
		if (!std::getline(std::cin, value))
			return ("");
		if (!value.empty())
			break ;
		std::cout << name << " shouldn't be empty > ";
	}
	return (value);
}

PhoneBook::~PhoneBook(void) {}
