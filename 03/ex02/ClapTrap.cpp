#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(std::string name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Constructor of Claptrap (named " << name << ")" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Desctuctor of Claptrap (named " << name << ")" << std::endl;
}

void ClapTrap::attack(std::string const & target)
{
	if (energyPoints < 10)
	{
		std::cout << name << " hasn't enough energy points left to attack (";
		std::cout << energyPoints << " energy points remaining, 10 needed)" << std::endl;
		return ;
	}
	energyPoints -= 10;
	std::cout << name;
	std::cout << " attacks " << target;
	std::cout << ", causing " << attackDamage;
	std::cout << " points of damage! (" << energyPoints;
	std::cout << " energy points remaining)" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints < amount)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << name;
	std::cout << " receives " << amount;
	std::cout << " points of damage, " << hitPoints;
	std::cout << " hitpoints remaining" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	hitPoints += amount;
	std::cout << name;
	std::cout << " receives " << amount;
	std::cout << " points of healing, " << hitPoints;
	std::cout << " hitpoints remaining" << std::endl;
}
