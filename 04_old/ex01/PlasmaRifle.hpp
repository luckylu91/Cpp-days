#pragma once
#include "AWeapon.hpp"
#include <string>
#include <iostream>

class PlasmaRifle: public AWeapon
{
public:
	PlasmaRifle();
	PlasmaRifle(PlasmaRifle const &);
	~PlasmaRifle();
	PlasmaRifle & operator=(PlasmaRifle const &);
	void attack() const;
};
