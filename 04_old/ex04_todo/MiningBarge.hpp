#pragma once
#include "IMiningLaser.hpp"
#include "IAsteroid.hpp"

class MiningBarge
{
private:
	IMiningLaser	*lasers[4];
	int				length;
public:
	MiningBarge();
	void equip(IMiningLaser *);
	void mine(IAsteroid *) const;
};


