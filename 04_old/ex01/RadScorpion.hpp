#pragma once
#include "Enemy.hpp"
#include <string>

class RadScorpion : public Enemy
{
private:
	void init();
public:
	RadScorpion();
	RadScorpion(RadScorpion const &);
	~RadScorpion();
	RadScorpion & operator=(RadScorpion const &);
	void takeDamage(int damage);
};
