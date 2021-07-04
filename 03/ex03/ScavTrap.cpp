#include "ScavTrap.hpp"
#include <iostream>
#include <string>

void ScavTrap::_init()
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "Constructor of ScavTrap" << std::endl;
}

ScavTrap::ScavTrap() { _init(); }

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) { _init(); }

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor of ScavTrap (named " << name << ")" << std::endl;
}

void ScavTrap::attack(std::string const & target)
{
	if (energyPoints < 20)
	{
		std::cout << name << " hasn't enough energy points left to attack (";
		std::cout << energyPoints << " energy points remaining, 20 needed)" << std::endl;
		return ;
	}
	energyPoints -= 20;
	std::cout << name;
	std::cout << " scav-trap-style attacks " << target;
	std::cout << ", causing " << attackDamage;
	std::cout << " points of damage! (" << energyPoints;
	std::cout << " energy points remaining)" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << name << " has entered in Gate Keeper Mode" << std::endl;
}
