#include <iostream>
#include <string>
// #include <cstdlib>
#include <sstream>
#include <stdlib.h>
#include "Contact.hpp"

static void print_ten(std::string const &str)
{
	size_t	length = str.length();
	size_t	i = 0;
	size_t	j = 0;

	while (i + length < 10)
	{
		std::cout << ' ';
		i++;
	}
	while (i + j < 9)
	{
		std::cout << str[j];
		j++;
	}
	if (length <= 10)
		std::cout << str[j];
	else
		std::cout << '.';
}

// index,prénom,nom de famille et pseudo
static void print_contact_line(Contact &contact)
{
	std::cout << '|';
	for (int i = 0; i < 9; i++)
		std::cout << ' ';
	std::cout << contact.index;
	std::cout << '|';
	print_ten(contact.first_name);
	std::cout << '|';
	print_ten(contact.last_name);
	std::cout << '|';
	print_ten(contact.login);
	std::cout << '|';
	std::cout << std::endl;
}

static void print_search_array(Contact *contacts, int number_of_contacts)
{
	std::cout << std::endl;
	std::cout << '|';
	print_ten("index");
	std::cout << '|';
	print_ten("first name");
	std::cout << '|';
	print_ten("last name");
	std::cout << '|';
	print_ten("login");
	std::cout << '|';
	std::cout << std::endl;
	std::cout << std::string(45, '-') << std::endl;
	for (int j = 0; j < number_of_contacts; j++)
		print_contact_line(contacts[j]);
	std::cout << std::string(45, '-') << std::endl;
}

int	main()
{
	Contact		contacts[8];
	int			i = 0;
	std::string	command;

	while (true)
	{
		std::cout << "Enter a command in { ADD, SEARCH, EXIT } : ";
		getline(std::cin, command);
		if (command == "ADD")
		{
			if (i < 8)
			{
				contacts[i].initialize(i);
				i++;
			}
			else
				std::cout << "Il y a plus de place, arrete d'ADD s'il te plait" << std::endl;
		}
		else if (command == "SEARCH")
		{
			if (i == 0)
			{
				std::cout << "La liste de contact est vide, rien a chercher." << std::endl;
				continue ;
			}
			int		search_index;
			std::string	index_str;
			bool	index_ok;
			do
			{
				print_search_array(contacts, i);
				std::cout << "Veuillez specifier un index pour la recherche : ";
				getline(std::cin, index_str);
				search_index = atoi(index_str.c_str());
				index_ok = true;
				if (index_str.find_first_not_of("0123456789") != std::string::npos)
				{
					std::cout << "Erreur, l'entree n'est pas un nombre au format valide (pas de + ou de -)" << std::endl;
					index_ok = false;
				}
				else if (search_index < 0 || search_index >= i)
				{
					std::cout << "L'indice n'est pas valide" << std::endl;
					index_ok = false;
				}
			} while (!index_ok);
			std::cout << contacts[search_index] << std::endl;
		}
		else if (command == "EXIT")
			break ;
	}
	return (0);
}
