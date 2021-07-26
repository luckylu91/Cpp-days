#pragma once
#include <string>
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	Dog(Dog const &);
	Dog & operator=(Dog const &);
	virtual void makeSound() const;
};
