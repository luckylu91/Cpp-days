#include "HumanB.hpp"
#include <string>

HumanB::HumanB(std::string name): name(name) {}

void HumanB::setWeapon(Weapon newWeapon)
{
	weapon = newWeapon;
}
