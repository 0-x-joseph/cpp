/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:18:04 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/22 18:47:04 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <cctype>


Contact::Contact(void) {
	this->is_empty = true;
};

Contact::Contact(std::string& f, std::string& l, std::string& n, std::string& nbr, std::string& s)
	: first_name(f), last_name(l), nickname(n), phone_number(nbr), secret(s)
{
	this->is_empty = false;
}

bool	Contact::is_valid_phonenumber(std::string& nbr)
{
	std::string::iterator it_begin = nbr.begin();

	it_begin = nbr.begin();
	if (*it_begin == '+')
		++it_begin;
	for (std::string::iterator it = it_begin; it != nbr.end(); ++it)
	{
		if (!std::isdigit(*it))
			return (false);
	}
	return (true);
}

std::string	Contact::truncate(std::string& str, unsigned int width, int& left) {
	if (str.length() > width) {
		left = 0;
		return (str.substr(0, width - 1) + '.');
	}
	left = width - str.length();
	return (str);
}

bool	Contact::empty(void) const {
	return (this->is_empty);
}

Contact::~Contact(void) {};
