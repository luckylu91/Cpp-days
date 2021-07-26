#pragma once
#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain * _brain;
	void _copy(Cat const &);
public:
	Cat();
	~Cat();
	Cat(Cat const &);
	Cat & operator=(Cat const &);
	virtual void makeSound() const;
};
