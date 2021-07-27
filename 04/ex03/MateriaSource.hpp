#pragma once
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*inventory[4];
	int			n_materias;
	void		_copy(MateriaSource const & other);
	void		_delete();
public:
	MateriaSource();
	MateriaSource(MateriaSource const &);
	virtual ~MateriaSource();
	MateriaSource & operator=(MateriaSource const &);
	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
};
