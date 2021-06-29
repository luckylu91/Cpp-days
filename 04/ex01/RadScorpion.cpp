#include "RadScorpion.hpp"
#include <string>
#include <iostream>

void RadScorpion::init()
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion") { init(); }

RadScorpion::RadScorpion(RadScorpion const & other) : Enemy(other) { init(); }

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion & RadScorpion::operator=(RadScorpion const & other)
{
	Enemy::operator=(other);
	return *this;
}

void RadScorpion::takeDamage(int damage)
{
	std::cout << "You touched a scorpion... With a bullet." << std::endl;
	Enemy::takeDamage(damage);
}
