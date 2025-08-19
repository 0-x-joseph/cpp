#include "PhoneBook.hpp"
#include "Contact.hpp"

/*
class PhoneBook {

public:

	PhoneBook(void);

	void	add(Contact contact);

	void	search(Contact contact);

	void	display(void);

private:
	Contact	contacts[9];
};
*/

std::string only_ten(std::string& str, int col_width)
{
	int			len;
	std::string	ws_str;

	len = str.length();
	if (len >= col_width)
		return (str.substr(0, 9) + '.');
	for (int i = len - 1; i < col_width; i++)
		ws_str.append(" ");
	return (str + ws_str);
}

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
	std::cout << TABLE_HEADER << std::endl;

	for (int i = 0; i < this->top; i++) {
		std::cout << " " << i << "         " << " " << "|";
		std::cout << " " << only_ten(this->contacts[i].first_name, this->column_width) << " " << "|";
		std::cout << " " << only_ten(this->contacts[i].last_name, this->column_width) << " " << "|";
		std::cout << " " << only_ten(this->contacts[i].nickname, this->column_width) << std::endl;
	}
}


void	PhoneBook::search(Contact contact)
{
	(void)contact;
	return ;
}
