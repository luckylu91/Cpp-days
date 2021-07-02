#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const & other) : AMateria("cure"), _xp(other._xp) {}

Cure::~Cure() {}

Cure & Cure::operator=(Cure const & other)
{
	AMateria::operator=(other);
	return *this;
}

Cure* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
