#pragma once
#include <string>
#include <iostream>

class Animal
{
protected:
	Animal();
	Animal(std::string const & type);
	Animal(Animal const &);
	std::string _type;
public:
	virtual Animal & operator=(Animal const &) = 0;
	virtual ~Animal();
	virtual void makeSound() const = 0;
	std::string getType() const;
};
