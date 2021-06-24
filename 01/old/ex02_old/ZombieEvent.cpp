#include "ZombieEvent.hpp"
#include <cstdlib>

std::string ZombieEvent::syllables[] = {
	"ma", "hu", "gi", "shi", "ni", "ta", "hi"
};
int ZombieEvent::syllablesSize = \
	sizeof(ZombieEvent::syllables) / sizeof(std::string);

ZombieEvent::ZombieEvent(): type("standard_zombie") {}
ZombieEvent::ZombieEvent(std::string type): type(type) {}

void ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie * ZombieEvent::newZombie(std::string name)
{
	return new Zombie(this->type, name);
}

Zombie * ZombieEvent::randomChump()
{
	int num_syllables = rand() % 2 + 2;
	std::string name;
	for (int i = 0; i < num_syllables ; i++)
	{
		int i_syllables = rand() % ZombieEvent::syllablesSize;
		std::string syll = ZombieEvent::syllables[i_syllables];
		if (i == 0)
			syll[0] = toupper(syll[0]);
		name.append(syll);
	}
	Zombie * newcommer = new Zombie(this->type, name);
	newcommer->tease();
	return newcommer;
}
