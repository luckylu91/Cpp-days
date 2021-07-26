#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Default Constructor of Dog" << std::endl;
}

Dog::Dog(Dog const & other) : Animal("Dog")
{
	(void) other;
	std::cout << "Copy Constructor of Dog" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor of Dog" << std::endl;
}

Dog & Dog::operator=(Dog const & other)
{
	(void) other;
	std::cout << "Assignation Operator of Dog" << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Waf" << std::endl;
}
