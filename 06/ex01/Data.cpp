#include "Data.hpp"
#include <cstring>

bool Data::operator==(Data const & other) const
{
	return n == other.n && strncmp(comment, other.comment, 250) == 0;
};
