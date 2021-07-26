#pragma once
#include "Enemy.hpp"
#include <string>

class SuperMutant : public Enemy
{
private:
	void init();
public:
	SuperMutant();
	SuperMutant(SuperMutant const &);
	~SuperMutant();
	SuperMutant & operator=(SuperMutant const &);
	void takeDamage(int damage);
};
