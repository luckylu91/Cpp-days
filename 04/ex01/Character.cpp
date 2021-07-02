#include "Character.hpp"
#include <string>
#include <iostream>

Character::Character(std::string const & name) : name(name), ap(40), weapon(nullptr) {}

Character::Character(Character const & other) : name(other.name), ap(40), weapon(nullptr) {}

Character::~Character() {}

Character & Character::operator=(Character const & other)
{
	name = other.name;
	return *this;
}

std::string const & Character::getName() const
{
	return name;
}

bool Character::hasWeapon() const
{
	return (weapon != NULL);
}

std::string Character::getWeaponName() const
{
	if (!hasWeapon())
		return "NO_WEAPON";
	else
		return weapon->getName();
}

int Character::getAP() const
{
	return ap;
}

void Character::recoverAP()
{
	int amount;

	if (ap > 30)
	{
		amount = 40 - ap;
		ap = 40;
	}
	else
	{
		amount = 10;
		ap += 10;
	}
	std::cout << name << " recovered " << amount << " AP" << std::endl;
}

void Character::equip(AWeapon * newWeapon)
{
	weapon = newWeapon;
}

void Character::attack(Enemy * enemy)
{
	if (!weapon)
		return ;
	if (ap < weapon->getAPCost())
	{
		std::cout << "Not enough AP (" << ap << " posessed, and ";
		std::cout << weapon->getAPCost() << "required)" << std::endl;
		return ;
	}
	ap -= weapon->getAPCost();
	std::cout <<  name << " attacks " << enemy->getType();
	std::cout << " with a " << weapon->getName()  << std::endl;
	weapon->attack();
	enemy->takeDamage(weapon->getDamage());
	if (enemy->getHP() == 0)
		delete enemy;
}

std::ostream & operator<<(std::ostream & os, Character const & c)
{
	if (c.hasWeapon())
		os << c.getName() << " has " << c.getAP() << " AP and wields a " << c.getWeaponName() << std::endl;
	else
		os << c.getName() << " has " << c.getAP() << " AP and is unarmed" << std::endl;
	return os;
}
