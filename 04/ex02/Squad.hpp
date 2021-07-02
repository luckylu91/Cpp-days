#pragma once
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
#include <cstddef>

class Squad : public ISquad
{
private:
	ISpaceMarine **marines;
	int n_marines;
	int size;
public:
	Squad();
	Squad(Squad const &);
	~Squad();
	Squad & operator=(Squad const &);
	virtual int getCount() const;
	virtual ISpaceMarine* getUnit(int) const;
	virtual int push(ISpaceMarine*);
};

Squad::Squad() : marines(NULL), n_marines(0), size(0) {}

Squad::Squad(Squad const & other)
{
}

Squad::~Squad()
{
}

Squad & Squad::operator=(Squad const & other)
{
	return *this;
}

int Squad::getCount() const
{
	return n_marines;
}

ISpaceMarine* Squad::getUnit(int i) const
{
	if (i >= 0 && i < n_marines)
		return marines[i];
	else
		return NULL;
}

int Squad::push(ISpaceMarine*)
{
	if (n_marines == size && size > 0)
		delete [] marines;
	marines = new *
		
	n_marines++;
}
