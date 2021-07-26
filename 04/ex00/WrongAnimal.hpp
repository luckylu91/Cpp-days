#pragma once
#include <string>
#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(std::string const & type);
	WrongAnimal(WrongAnimal const &);
	WrongAnimal & operator=(WrongAnimal const &);
	virtual ~WrongAnimal();
	void makeSound() const;
	std::string getType() const;
};
