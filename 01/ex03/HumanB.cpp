#include "HumanB.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(std::string name): name(name) {}

void HumanB::setWeapon(Weapon & newWeapon)
{
	weapon = &newWeapon;
}

void HumanB::attack()
{
	std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}
