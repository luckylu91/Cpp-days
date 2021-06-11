#pragma once
#include <string>

class Contact
{
public:
	int			index;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	login;
	std::string	postal_address;
	std::string	email_address;
	std::string	phone_number;
	std::string	birthday_date;
	std::string	favorite_meal;
	std::string	underwear_color;
	std::string	darkest_secret;
	void	initialize(int idx);
};

std::ostream &operator<<(std::ostream &ostr, Contact &contact);
