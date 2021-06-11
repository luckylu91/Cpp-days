#pragma once
#include <string>

class Weapon
{
	std::string type;
public:
	Weapon();
	Weapon(std::string type);
	std::string const & getType() const;
	void setType(std::string newType);
};
