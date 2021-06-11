#pragma once
#include <string>
#include "Zombie.hpp"

class ZombieEvent
{
	std::string type;
	static std::string syllables[];
	static int syllablesSize;
public:
	ZombieEvent();
	ZombieEvent(std::string type);
	void setZombieType(std::string type);
	Zombie * newZombie(std::string name);
	Zombie * randomChump();
};



