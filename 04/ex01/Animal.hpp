#pragma once
#include <string>
#include <iostream>

class Animal
{
protected:
	std::string _type;
public:
	Animal();
	Animal(std::string const & type);
	Animal(Animal const &);
	Animal & operator=(Animal const &);
	virtual ~Animal();
	virtual void makeSound() const;
	std::string getType() const;
};
