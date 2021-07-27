#include "Character.hpp"

void Character::_copy(Character const & other)
{
	for (int j = 0; j < other.n_materias; j++)
	{
		inventory[j] = other.inventory[j]->clone();
	}
}

void Character::_delete()
{
	for (int i = 0; i < n_materias; i++)
	{
		std::cout << "Deleting " << inventory[i]->getType();
		std::cout << " materia from " << name << "'s inventory" << std::endl;
		delete inventory[i];
	}
}

Character::Character(std::string const & name) : name(name), n_materias(0) {}

Character::Character(Character const & other) : name(other.name), n_materias(other.n_materias)
{
	_copy(other);
}

Character::~Character()
{
	_delete();
}

Character & Character::operator=(Character const & other)
{
	_delete();
	name = other.name;
	n_materias = other.n_materias;
	_copy(other);
	return *this;
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	if (n_materias == 4 || m == NULL)
		return ;
	inventory[n_materias++] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= n_materias)
		return ;
	for (int i = idx; i < n_materias - 1; i++)
	{
		inventory[i] = inventory[i + 1];
	}
	n_materias--;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= n_materias)
		return ;
	inventory[idx]->use(target);
}
