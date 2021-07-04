#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), name(name)
{
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "Constructor of DiamondTrap (named " << name << ")" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor of DiamondTrap (named " << name << ")" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "Who am I ? My heart says " << ClapTrap::name << " but my CPU says " << name << std::endl;
}
