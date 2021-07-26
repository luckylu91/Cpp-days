#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type), _xp(0) {}

AMateria::~AMateria() {}

AMateria & AMateria::operator=(AMateria const & other)
{
	_xp = other._xp;
	return *this;
}

std::string const & AMateria::getType() const
{
	return type;
}

unsigned int AMateria::getXP() const
{
	return _xp;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	_xp += 10;
}
