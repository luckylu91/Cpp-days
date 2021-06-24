#include "Brain.hpp"
#include "Human.hpp"

Brain const & Human::getBrain() const
{
	return brain;
}

std::string Human::identify() const
{
	return brain.identify();
}
