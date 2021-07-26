#include "MateriaSource.hpp"

void MateriaSource::_copy(MateriaSource const & other)
{
	for (int j = 0; j < other.n_materias; j++)
	{
		inventory[j] = other.inventory[j];
	}
}

MateriaSource::MateriaSource() : n_materias(0) {}

MateriaSource::MateriaSource(MateriaSource const & other) : n_materias(other.n_materias)
{
	_copy(other);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < n_materias; i++)
		delete inventory[i];
}

MateriaSource & MateriaSource::operator=(MateriaSource const & other)
{
	n_materias = other.n_materias;
	_copy(other);
	return *this;
}

void MateriaSource::learnMateria(AMateria * m)
{
	if (n_materias == 4 || m == NULL)
		return ;
	inventory[n_materias++] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < n_materias; i++)
	{
		if (type == inventory[i]->getType())
			return inventory[i]->clone();
	}
	return NULL;
}
