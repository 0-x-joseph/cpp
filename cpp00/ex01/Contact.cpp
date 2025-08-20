/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:18:04 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/20 10:18:05 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


Contact::Contact(void) {};

Contact::Contact(std::string& f, std::string& l, std::string& n, std::string& nbr, std::string& s)
	: first_name(f), last_name(l), nickname(n), phone_number(nbr), secret(s) {}

std::string	Contact::truncate(std::string& str, unsigned int width, int& left)
{
	if (str.length() > width) {
		left = 0;
		return (str.substr(0, width - 1) + '.');
	}
	left = width - str.length();
	return (str);
}

Contact::~Contact(void) {};
