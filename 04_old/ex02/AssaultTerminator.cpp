
#include "AssaultTerminator.hpp"
#include <iostream>

void AssaultTerminator::_init()
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator() { _init(); }

AssaultTerminator::AssaultTerminator(AssaultTerminator const & other) {
	(void)other;
	_init();
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I’ll be back..." << std::endl;
}

AssaultTerminator & AssaultTerminator::operator=(AssaultTerminator const & other)
{
	(void)other;
	return *this;
}

ISpaceMarine* AssaultTerminator::clone() const
{
	return new AssaultTerminator(*this);
}

void AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}
