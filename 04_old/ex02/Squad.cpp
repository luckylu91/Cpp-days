#include "Squad.hpp"

bool Squad::_is_empty() const
{
	return size == 0;
}

void Squad::_clone(Squad const & other)
{
	size = other.size;
	n_marines = other.n_marines;
	if (other._is_empty())
		marines = NULL;
	else
		marines = new ISpaceMarine *[size];
}

Squad::Squad() : marines(NULL), n_marines(0), size(0) {}

Squad::Squad(Squad const & other) { _clone(other); }

Squad::~Squad()
{
	if (!_is_empty())
	{
		for (int i = 0; i < n_marines; i++)
			delete marines[i];
		delete [] marines;
	}
}

Squad & Squad::operator=(Squad const & other)
{
	if (!_is_empty())
	{
		for (int i = 0; i < n_marines; i++)
		{
			bool found = false;
			for (int j = 0; j < other.n_marines; j++)
			{
				if (marines[i] == marines[j])
				{
					found = true;
					break ;
				}
			}
			if (!found)
				delete marines[i];
		}
		delete [] marines;
	}
	_clone(other);
	return *this;
}

int Squad::getCount() const
{
	return n_marines;
}

ISpaceMarine* Squad::getUnit(int i) const
{
	if (i < 0 || i >= n_marines)
		return NULL;
	return marines[i];
}

int Squad::push(ISpaceMarine* marine)
{
	if (marine == NULL)
		return n_marines;
	for (int i = 0; i < n_marines; i++)
	{
		if (marines[i] == marine)
			return n_marines;
	}
	if (size == n_marines)
	{
		if (!_is_empty())
			delete [] marines;
		marines = new ISpaceMarine *[size += 5];
	}
	marines[n_marines++] = marine;
	return n_marines;
}
