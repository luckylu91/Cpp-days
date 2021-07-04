#pragma once
#include "ClapTrap.hpp"
#include <string>

class FragTrap : virtual public ClapTrap
{
private:
	void _init();
protected:
	FragTrap();
public:
	FragTrap(std::string name);
	~FragTrap();
	void attack(std::string const & target);
	void highFivesGuys(void);
};
