#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap() {}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "Constructor of FragTrap (named " << name << ")" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor of FragTrap (named " << name << ")" << std::endl;
}

void FragTrap::attack(std::string const & target)
{
	if (energyPoints < 15)
	{
		std::cout << name << " hasn't enough energy points left to attack (";
		std::cout << energyPoints << " energy points remaining, 20 needed)" << std::endl;
		return ;
	}
	energyPoints -= 15;
	std::cout << name;
	std::cout << " fRaG-StYlE attacks " << target;
	std::cout << ", causing " << attackDamage;
	std::cout << " points of damage! (" << energyPoints;
	std::cout << " energy points remaining)" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "Requesting high fives" << std::endl;
}
