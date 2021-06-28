#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10),
	energyPoints(10), attackDamage(0) {}

void ClapTrap::attack(std::string const & target)
{
	std::cout << "FR4G-TP " << name;
	std::cout << " attacks " << target;
	std::cout << ", causing " << attackDamage;
	std::cout << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "FR4G-TP " << name;
	std::cout << " received " << amount;
	std::cout << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{

}
