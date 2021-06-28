#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	{
		ClapTrap c("Jean-Le-Trap");

		c.attack("Baptiste");
		c.attack("Jean-Pierre");
		c.takeDamage(9);
		c.beRepaired(1);
	}
	std::cout << std::endl;
	{
		ScavTrap s("Arnaud-Le-Scav");

		s.attack("Jean-Xaxier");
		s.attack("Jean-Mouloud");
		s.attack("Jean-Denis");
		s.takeDamage(99);
		s.beRepaired(199);
		s.guardGate();
	}
}