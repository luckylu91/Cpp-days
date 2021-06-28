#include "Peon.hpp"
#include <string>
#include <iostream>

void Peon::init()
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(std::string name) : Victim(name) { init(); }

Peon::Peon(Peon const & other) : Victim(other.name) { init(); }

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon & Peon::operator=(Peon const & other)
{
	name = other.name;
	return *this;
}


void Peon::getPolymorphed() const
{
	std::cout << name << " has been turned into a pink pony!" << std::endl;
}
