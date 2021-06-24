#include "ZombieHorde.hpp"
#include <cstdlib>

std::string ZombieHorde::syllables[] = {
	"ma", "hu", "gi", "shi", "ni", "ta", "hi"
};
int ZombieHorde::syllablesSize = \
	sizeof(ZombieHorde::syllables) / sizeof(std::string);

static std::string randomName()
{
	int num_syllables = rand() % 2 + 2;
	std::string name;
	for (int i = 0; i < num_syllables ; i++)
	{
		int i_syllables = rand() % ZombieHorde::syllablesSize;
		std::string syll = ZombieHorde::syllables[i_syllables];
		if (i == 0)
			syll[0] = toupper(syll[0]);
		name.append(syll);
	}
	return (name);
}

ZombieHorde::ZombieHorde(int n)
{
	this->n = n;
	this->horde = new Zombie[n];
	for (int i = 0; i < n; i++)
	{
		horde[i].type = "social_zombie";
		horde[i].name = randomName();
	}
}

ZombieHorde::~ZombieHorde()
{
	delete [] horde;
}

void ZombieHorde::announce()
{
	for (int i = 0; i < n; i++)
		horde[i].tease();
}
