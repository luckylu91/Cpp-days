#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>
#include <iostream>

class Ice : public AMateria
{
private:
	Ice & operator=(Ice const &);
	Ice(Ice const &);

public:
	Ice();
	virtual ~Ice();

	virtual Ice* clone() const;
	virtual void use(ICharacter& target);
};
