#include "Sorcerer.hpp"
#include "Victim.hpp"
#include <string>
#include <iostream>

void Sorcerer::init()
{
	std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(std::string name, std::string title) : name(name), title(title) { init(); }

Sorcerer::Sorcerer(Sorcerer const & other): name(other.name), title(other.title) { init(); }

Sorcerer::~Sorcerer()
{
	std::cout << name << ", " << title << ", is dead. Consequences will never be the same!" << std::endl;
}

std::string Sorcerer::getName() const
{
	return name;
}

std::string Sorcerer::getTitle() const
{
	return title;
}

Sorcerer & Sorcerer::operator=(Sorcerer const & other)
{
	name = other.name;
	title = other.title;
}

std::ostream & operator<<(std::ostream const & os, Sorcerer const & sorcerer)
{
	std::cout << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies!" << std::endl;
}

void Sorcerer::polymorph(Victim const & victim) const
{
	victim.getPolymorphed();
}
