#include "SuperMutant.hpp"
#include <string>
#include <iostream>

void SuperMutant::init()
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant") { init(); }

SuperMutant::SuperMutant(SuperMutant const & other) : Enemy(other) { init(); }

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh..." << std::endl;
}

SuperMutant & SuperMutant::operator=(SuperMutant const & other)
{
	Enemy::operator=(other);
	return *this;
}

void SuperMutant::takeDamage(int damage)
{
	std::cout << "This fellow is a mutant. What's mor he's super, so he takes ";
	std::cout << damage - 3 << " damage instead of " << damage << std::endl;
	Enemy::takeDamage(damage - 3);
}
