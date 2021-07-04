#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
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
	std::cout << std::endl;
	{
		FragTrap f("Thierry-Le-Frag");

		f.attack("Jean-Jean");
		f.attack("Paul-Paul");
		f.attack("Guy-Guy");
		f.takeDamage(31);
		f.beRepaired(4);
		f.highFivesGuys();
	}
	std::cout << std::endl;
	{
		DiamondTrap d("François-Le-Diams");
		d.attack("La mort elle même");
		d.takeDamage(31);
		d.beRepaired(4);
		d.guardGate();
		d.highFivesGuys();
		d.whoAmI();
	}
}