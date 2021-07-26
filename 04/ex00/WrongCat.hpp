#pragma once
#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	~WrongCat();
	WrongCat(WrongCat const &);
	WrongCat & operator=(WrongCat const &);
	void makeSound() const;
};
