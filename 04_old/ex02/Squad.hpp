#pragma once
#include <iostream>
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"

class Squad : public ISquad
{
private:
	ISpaceMarine**	marines;
	int				n_marines;
	int				size;
	bool			_is_empty() const;
	void			_clone(Squad const &);
public:
	Squad();
	Squad(Squad const &);
	~Squad();
	Squad & operator=(Squad const &);
	virtual int getCount() const;
	virtual ISpaceMarine* getUnit(int) const;
	virtual int push(ISpaceMarine*);
};
