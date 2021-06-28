#include "ClapTrap.hpp"

int main()
{
	ClapTrap c("Jean-Le-Trap");

	c.attack("Baptiste");
	c.attack("Jean-Pierre");
	c.takeDamage(9);
	c.beRepaired(1);
}