#pragma once
#include "ClapTrap.hpp"
#include <string>

class ScavTrap : virtual public ClapTrap
{
private:
	void _init();
protected:
	ScavTrap();
public:
	ScavTrap(std::string name);
	~ScavTrap();
	void attack(std::string const & target);
	void guardGate();
};
