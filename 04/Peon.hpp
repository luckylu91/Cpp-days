#pragma once
#include "Victim.hpp"
#include <string>

class Peon : public Victim
{
public:
	Peon(std::string name);
	~Peon();
};
