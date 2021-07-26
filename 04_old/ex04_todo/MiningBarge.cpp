#include "MiningBarge.hpp"

void MiningBarge::equip(IMiningLaser * laser)
{
	if (length < 4)
		this->lasers[this->length++] = laser;
}

void MiningBarge::mine(IAsteroid * asteroid) const
{
	for (int i = 0; i < this->length; i++)
	{
		this->lasers[i]->mine(asteroid);
	}
}
