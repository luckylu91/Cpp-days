#include "Brain.hpp"
#include <string>
#include <sstream>
#include <stdint.h>

// Brain::Brain(size_t vol) : volume(vol) {}

std::string Brain::identify() const
{
	std::ostringstream oss;
	oss << "0x";
	oss.flags(std::ios::hex | std::ios::uppercase);
	oss << (uintptr_t)this;
	return oss.str();
}
