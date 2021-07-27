#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(AMateria const & other) : type(other.type) {}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const { return type; }

void AMateria::use(ICharacter &) {}
