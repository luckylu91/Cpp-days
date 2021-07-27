#pragma once
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
private:
	virtual AMateria & operator=(AMateria const &);
protected:
	std::string type;
	AMateria();
	AMateria(std::string const & type);
	AMateria(AMateria const & other);
public:
	virtual ~AMateria();

	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
