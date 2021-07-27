#pragma once
#include <string>
#include <iostream>

class Animal
{
private:
	Animal();
	Animal(Animal const &);
	virtual Animal & operator=(Animal const &);
protected:
	std::string _type;
	Animal(std::string const & type);
public:
	virtual ~Animal();
	virtual void makeSound() const = 0;
	std::string getType() const;
};
