#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Default Constructor of WrongCat" << std::endl;
}

WrongCat::WrongCat(WrongCat const & other) : WrongAnimal("WrongCat")
{
	(void) other;
	std::cout << "Copy Constructor of WrongCat" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor of WrongCat" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & other)
{
	(void) other;
	std::cout << "Assignation Operator of WrongCat" << std::endl;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}
