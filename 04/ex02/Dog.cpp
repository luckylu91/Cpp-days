#include "Dog.hpp"

void Dog::_copy(Dog const & other)
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

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
	std::cout << "Default Constructor of Dog" << std::endl;
}

Dog::Dog(Dog const & other) : Animal("Dog")
{
	std::cout << "Copy Constructor of Dog" << std::endl;
	this->_brain = new Brain(*other._brain);
}

Dog::~Dog()
{
	std::cout << "Destructor of Dog" << std::endl;
	delete _brain;
}

Dog & Dog::operator=(Dog const & other)
{
	std::cout << "Assignation Operator of Dog" << std::endl;
	_copy(other);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Waf" << std::endl;
}
