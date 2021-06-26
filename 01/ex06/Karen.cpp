#include "Karen.hpp"
#include <iostream>
#include <string>

void Karen::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra baconfor my 7XL-double-cheese-triple-" \
		"pickle-special-ketchup burger. I just love it!" << std::endl;
	std::cout << std::endl;
}

void Karen::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extrabacon cost more money. " \
		"You don’t put enough! If you did I would not have to askfor it!" << std::endl;
	std::cout << std::endl;
}

void Karen::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. " \
	"I’ve beencoming here for years and you just started working here last month." << std::endl;
	std::cout << std::endl;
}

void Karen::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void Karen::unknown( void )
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Karen::complain_starting_at( std::string level )
{
	static std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	static complaint_fun_t levels_methods[] = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error
	};
	int	i;

	for (i = 0; i < 4; i++)
	{
		if (level == levels[i])
			break;
	}
	if (i == 4)
		unknown();
	for (; i < 4; i++)
	{
		(this->*(levels_methods[i]))();
	}
}
