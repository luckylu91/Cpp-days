#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include <string>
#include <iostream>

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) {}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & other) : AWeapon(other) {}

PlasmaRifle::~PlasmaRifle() {}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & other)
{
	AWeapon::operator=(other);
	return *this;
}

void PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
