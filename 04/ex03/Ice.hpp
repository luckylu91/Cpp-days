#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>
#include <iostream>

class Ice : public AMateria
{
public:
	Ice & operator=(Ice const &);
	Ice(Ice const &);
	Ice();
	virtual ~Ice();

	virtual Ice* clone() const;
	virtual void use(ICharacter& target);
};
