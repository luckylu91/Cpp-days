#pragma once
#include "ClapTrap.hpp"
#include <string>

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(std::string name);
	~ScavTrap();
	void attack(std::string const & target);
	void guardGate();
};
