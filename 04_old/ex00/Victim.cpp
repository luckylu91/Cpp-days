#include "Victim.hpp"
#include <string>
#include <iostream>

void Victim::init()
{
	std::cout << "Some random victim called " << name << " just appeared!" << std::endl;
}

Victim::Victim(std::string name) : name(name) { init(); }

Victim::Victim(Victim const & other) : name(other.name) { init(); }

Victim::~Victim()
{
	std::cout << "Victim " << name << " just died for no apparent reason!" << std::endl;
}

Victim & Victim::operator=(Victim const & other)
{
	name = other.name;
	return *this;
}

std::string Victim::getName() const
{
	return name;
}

std::ostream & operator<<(std::ostream & os, Victim const & victim)
{
	os << "I'm " << victim.getName() << " and I like otters!" << std::endl;
	return os;
}

void Victim::getPolymorphed() const
{
	std::cout << name << " has been turned into a cute little sheep!" << std::endl;
}
