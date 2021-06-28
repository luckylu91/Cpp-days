#include "Victim.hpp"
#include <string>
#include <iostream>

Victim::Victim(std::string name)
{
	std::cout << "Some random victim called " << name << " just appeared!" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << name << " just died for no apparent reason!" << std::endl;
}

std::string Victim::getName() const
{
	return name;
}


std::ostream & operator<<(std::ostream const & os, Victim const & victim)
{
	std::cout << "I'm " << victim.getName() << " and I like otters!" << std::endl;
}

void Victim::getPolymorphed() const
{
	std::cout << name << " has been turned into a cute little sheep!" << std::endl;
}
