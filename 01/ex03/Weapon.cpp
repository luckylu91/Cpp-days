#include "Weapon.hpp"

Weapon::Weapon() {}
Weapon::Weapon(std::string type): type(type) {}

std::string const & Weapon::getType() const
{
	return type;
}

void Weapon::setType(std::string newType)
{
	type = newType;
}
