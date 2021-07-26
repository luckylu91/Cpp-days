#pragma once
#include "AWeapon.hpp"
#include <string>
#include <iostream>

class PowerFist: public AWeapon
{
public:
	PowerFist();
	PowerFist(PowerFist const &);
	~PowerFist();
	PowerFist & operator=(PowerFist const &);
	void attack() const;
};
