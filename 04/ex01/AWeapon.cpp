#include "AWeapon.hpp"
#include <string>
#include <iostream>

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
	: name(name), apcost(apcost), damage(damage) {}

AWeapon::AWeapon(AWeapon const & other)
	: name(other.name), apcost(other.apcost), damage(other.damage) {}

AWeapon::~AWeapon() {}

AWeapon & AWeapon::operator=(AWeapon const & other)
{
	name = other.name;
	apcost = other.apcost;
	damage = other.damage;
	return *this;
}

std::string const & AWeapon::getName() const
{
	return name;
}

int AWeapon::getAPCost() const
{
	return apcost;
}

int AWeapon::getDamage() const
{
	return damage;
}