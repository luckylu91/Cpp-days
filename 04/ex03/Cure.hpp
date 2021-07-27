#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>
#include <iostream>

class Cure : public AMateria
{
private:
	Cure(Cure const &);
	Cure & operator=(Cure const &);

public:
	Cure();
	virtual ~Cure();

	virtual Cure* clone() const;
	virtual void use(ICharacter& target);
};
