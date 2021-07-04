#include "Karen.hpp"
#include <iostream>
#include <string>

void Karen::debug( void )
{
	std::cout << "I love to get extra baconfor my 7XL-double-cheese-triple-" \
		"pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Karen::info( void )
{
	std::cout << "I cannot believe adding extra bacon cost more money. " \
		"You don’t put enough! If you did I would not have to askfor it!" << std::endl;
}

void Karen::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. " \
	"I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error( void )
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::complain( std::string level )
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
			(this->*(levels_methods[i]))();
	}
}
