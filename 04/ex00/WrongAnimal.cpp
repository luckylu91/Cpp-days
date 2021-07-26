#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default Constructor of WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const & type) : _type(type)
{
	std::cout << "Parametrized Constructor of WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & other)
{
	(void) other;
	std::cout << "Copy Constructor of WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor of WrongAnimal" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & other)
{
	(void) other;
	std::cout << "Assignation Operator of WrongAnimal" << std::endl;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "* WrongAnimal noise *" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return _type;
}
