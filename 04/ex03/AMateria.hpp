#pragma once
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string type;
	unsigned int _xp;
public:
	AMateria(std::string const & type);
	virtual ~AMateria();
	AMateria & operator=(AMateria const &);
	std::string const & getType() const;
	unsigned int getXP() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
