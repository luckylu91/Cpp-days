#pragma once
#include "IMiningLaser.hpp"
#include "IAsteroid.hpp"
#include <iostream>

class StripMiner : public IMiningLaser
{
public:
	void mine(IAsteroid *);
};

void StripMiner::mine(IAsteroid * asteroid)
{
	std::cout << "* strip mining... got " << asteroid->beMined(this) << "! *" << std::endl;
}