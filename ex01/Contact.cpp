#include "Contact.hpp"


Contact::Contact(void) {};

Contact::Contact(std::string fname, std::string lname, std::string nickname, std::string number, std::string secret)
{
	this->first_name = fname;
	this->last_name = lname;
	this->nickname = nickname;
	this->phone_number = number;
	this->secret = secret;
}

