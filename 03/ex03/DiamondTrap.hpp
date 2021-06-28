#pragma once
#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	name;
public:
	DiamondTrap(std::string name);
	~DiamondTrap();
	using ScavTrap::attack;
};
