#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>
#include <iostream>

class Cure : public AMateria
{
protected:
	std::string type;
	unsigned int _xp;
public:
	Cure();
	Cure(Cure const &);
	virtual ~Cure();
	Cure & operator=(Cure const &);
	virtual Cure* clone() const;
	virtual void use(ICharacter& target);
};
