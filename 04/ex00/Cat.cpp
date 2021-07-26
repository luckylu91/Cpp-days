#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Default Constructor of Cat" << std::endl;
}

Cat::Cat(Cat const & other) : Animal("Cat")
{
	(void) other;
	std::cout << "Copy Constructor of Cat" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor of Cat" << std::endl;
}

Cat & Cat::operator=(Cat const & other)
{
	(void) other;
	std::cout << "Assignation Operator of Cat" << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}
