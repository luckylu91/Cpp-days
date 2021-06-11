#pragma once
#include <string>
#include "Zombie.hpp"

class ZombieHorde
{
	int n;
	Zombie *horde;
public:
	static std::string syllables[];
	static int syllablesSize;
	ZombieHorde(int n);
	~ZombieHorde();
	void announce();
};
