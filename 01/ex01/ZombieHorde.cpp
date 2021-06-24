#include "ZombieHorde.hpp"
#include <cstdlib>

ZombieHorde::ZombieHorde(int n, std::string name)
{
	this->n = n;
	this->horde = new Zombie[n];
	for (int i = 0; i < n; i++)
	{
		horde[i].name = name;
	}
}

ZombieHorde::~ZombieHorde()
{
	delete [] horde;
}

void ZombieHorde::announce()
{
	for (int i = 0; i < n; i++)
		horde[i].announce();
}

void ZombieHorde::tease()
{
	for (int i = 0; i < n; i++)
		horde[i].tease();
}
