#pragma once
#include "Brain.hpp"
#include <iostream>

class Human
{
	Brain const brain;
public:
	Brain const & getBrain() const;
	std::string identify() const;
};
