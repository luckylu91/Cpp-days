#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>
#include <iostream>

class Ice : public AMateria
{
protected:
	std::string type;
	unsigned int _xp;
public:
	Ice();
	Ice(Ice const &);
	virtual ~Ice();
	Ice & operator=(Ice const &);
	virtual Ice* clone() const;
	virtual void use(ICharacter& target);
};
