#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>
#include <iostream>

class Cure : public AMateria
{
public:
	Cure(Cure const &);
	Cure & operator=(Cure const &);
	Cure();
	virtual ~Cure();

	virtual Cure* clone() const;
	virtual void use(ICharacter& target);
};
