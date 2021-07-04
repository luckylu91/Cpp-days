#pragma once
#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap
{
protected:
	FragTrap();
public:
	FragTrap(std::string name);
	~FragTrap();
	void attack(std::string const & target);
	void highFivesGuys(void);
};

