/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:42:42 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/22 18:42:20 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {

public:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	secret;

	static std::string	truncate(std::string& str, unsigned int width, int& left);
	static bool			is_valid_phonenumber(std::string& nbr);

	Contact(void);

	Contact(std::string& f, std::string& l, std::string& n, std::string& nbr, std::string& s);

	bool	empty(void) const;

	~Contact(void);

private:
	bool	is_empty;
};

#endif
