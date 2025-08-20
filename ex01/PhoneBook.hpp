/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:57:46 by ybouryal          #+#    #+#             */
/*   Updated: 2025/08/19 22:19:34 by ybouryal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

# include "Contact.hpp"

class PhoneBook {

public:

	PhoneBook(void);

	void	add(Contact contact);

	Contact	get_contact(void);

	void	search(int index);

	void	display(void);

private:
	Contact	contacts[8];
	int		top;
	int		max_contacts;
	int		column_width;

	void	display_one(int index);

	void	display_table_header(void);

	~PhoneBook(void);
};

#endif /* __PHONEBOOK_HPP__ */
