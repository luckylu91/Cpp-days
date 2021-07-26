#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria & AMateria::operator=(AMateria const &) { return *this; }

AMateria::~AMateria() {}

AMateria::AMateria(AMateria const & other) : type(other.type) {}

std::string const & AMateria::getType() const { return type; }

void AMateria::use(ICharacter &) {}
