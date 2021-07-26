#pragma once
#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain * _brain;
	void _copy(Dog const &);
public:
	Dog();
	~Dog();
	Dog(Dog const &);
	Dog & operator=(Dog const &);
	virtual void makeSound() const;
};
