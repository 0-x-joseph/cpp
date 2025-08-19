/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:57:46 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/19 12:21:15 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

# include "Contact.hpp"
# define TABLE_HEADER " index     | first name | last name  | nickname  "

class PhoneBook {

public:

	PhoneBook(void);

	void	add(Contact contact);

	void	search(Contact contact);

	void	display(void);

private:
	Contact	contacts[9];
	int		top;
	int		max_contacts;
	int		column_width;
};

#endif /* __PHONEBOOK_HPP__ */
