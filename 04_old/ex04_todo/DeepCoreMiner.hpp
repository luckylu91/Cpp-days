#pragma once
#include "IMiningLaser.hpp"
#include "IAsteroid.hpp"
#include <iostream>

class DeepCoreMiner : public IMiningLaser
{
public:
	void mine(IAsteroid *);
};

void DeepCoreMiner::mine(IAsteroid *asteroid)
{
	std::cout << "* mining deep... got " << asteroid->beMined(this) << "! *" << std::endl;
}