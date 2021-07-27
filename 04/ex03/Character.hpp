#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character : public ICharacter
{
private:
	std::string	name;
	AMateria	*inventory[4];
	int			n_materias;
	void		_copy(Character const & other);
	void		_delete();
public:
	Character(std::string const & name);
	Character(Character const &);
	virtual ~Character();
	Character & operator=(Character const &);
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};
