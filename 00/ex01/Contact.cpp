#include "Contact.hpp"
#include <iostream>

void Contact::initialize(int idx)
{
	index = idx;
	std::cout << "Veuillez repondre a ce mini questionnaire." << std::endl;
	std::cout << "first name ? ";
	getline(std::cin, first_name);
	std::cout << "last name ? ";
	getline(std::cin, last_name);
	std::cout << "nickname ? ";
	getline(std::cin, nickname);
	std::cout << "login ? ";
	getline(std::cin, login);
	std::cout << "postal address ? ";
	getline(std::cin, postal_address);
	std::cout << "email address ? ";
	getline(std::cin, email_address);
	std::cout << "phone number ? ";
	getline(std::cin, phone_number);
	std::cout << "birthday date ? ";
	getline(std::cin, birthday_date);
	std::cout << "favorite meal ? ";
	getline(std::cin, favorite_meal);
	std::cout << "underwear color ? ";
	getline(std::cin, underwear_color);
	std::cout << "darkest secret ? ";
	getline(std::cin, darkest_secret);
	std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &ostr, Contact &contact)
{
	std::cout << std::endl;
	ostr << "Contact number : " << contact.index << std::endl;
	ostr << "first name : " <<  contact.first_name << std::endl;
	ostr << "last name : " <<  contact.last_name << std::endl;
	ostr << "nickname : " <<  contact.nickname << std::endl;
	ostr << "login : " <<  contact.login << std::endl;
	ostr << "postal address : " <<  contact.postal_address << std::endl;
	ostr << "email address : " <<  contact.email_address << std::endl;
	ostr << "phone number : " <<  contact.phone_number << std::endl;
	ostr << "birthday date : " <<  contact.birthday_date << std::endl;
	ostr << "favorite meal : " <<  contact.favorite_meal << std::endl;
	ostr << "underwear color : " <<  contact.underwear_color << std::endl;
	ostr << "darkest secret : " <<  contact.darkest_secret << std::endl;
	std::cout << std::endl;
	return (ostr);
}
