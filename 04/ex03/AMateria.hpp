#pragma once
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string type;
	AMateria();
	AMateria(AMateria const & other);
	AMateria & operator=(AMateria const &);
public:
	AMateria(std::string const & type);
	virtual ~AMateria();

	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
