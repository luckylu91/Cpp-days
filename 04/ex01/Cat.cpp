#include "Cat.hpp"

void Cat::_copy(Cat const & other)
{
	if (this->_brain && other._brain)
		*this->_brain = *other._brain;
	else if (this->_brain)
	{
		delete this->_brain;
		this->_brain = NULL;
	}
	else if (other._brain)
		this->_brain = new Brain(*other._brain);
}

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
	std::cout << "Default Constructor of Cat" << std::endl;
}

Cat::Cat(Cat const & other) : Animal("Cat")
{
	std::cout << "Copy Constructor of Cat" << std::endl;
	this->_brain = new Brain(*other._brain);
}

Cat::~Cat()
{
	std::cout << "Destructor of Cat" << std::endl;
	delete _brain;
}

Cat & Cat::operator=(Cat const & other)
{
	std::cout << "Assignation Operator of Cat" << std::endl;
	_copy(other);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}
