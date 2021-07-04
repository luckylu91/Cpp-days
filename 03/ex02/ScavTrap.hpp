#pragma once
#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
protected:
	ScavTrap();
public:
	ScavTrap(std::string name);
	~ScavTrap();
	void attack(std::string const & target);
	void guardGate();
};
