#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default Constructor of Animal" << std::endl;
}

Animal::Animal(std::string const & type) : _type(type)
{
	std::cout << "Parametrized Constructor of Animal" << std::endl;
}

Animal::Animal(Animal const & other)
{
	(void) other;
	std::cout << "Copy Constructor of Animal" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor of Animal" << std::endl;
}

Animal & Animal::operator=(Animal const & other)
{
	(void) other;
	std::cout << "Assignation Operator of Animal" << std::endl;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "* Animal noise *" << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}
