#include "Brain.hpp"
#include <iostream>

void Brain::_copy(Brain const & other)
{
	std::cout << "Deep copying brain..." << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain::Brain()
{
	std::cout << "Default Constructor of Brain" << std::endl;
}

Brain::Brain(Brain const & other)
{
	std::cout << "Copy Constructor of Brain" << std::endl;
	_copy(other);
}

Brain::~Brain()
{
	std::cout << "Destructor of Brain" << std::endl;
}

Brain & Brain::operator=(Brain const & other)
{
	std::cout << "Assignation Operator of Brain" << std::endl;
	_copy(other);
	return *this;
}
