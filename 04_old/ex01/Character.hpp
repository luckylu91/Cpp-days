#pragma once
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include <string>

class Character
{
private:
	std::string	name;
	int			ap;
	AWeapon		*weapon;
public:
	Character(std::string const & name);
	Character(Character const &);
	~Character();
	Character & operator=(Character const &);
	std::string const & getName() const;
	bool hasWeapon() const;
	std::string getWeaponName() const;
	int getAP() const;
	void recoverAP();
	void equip(AWeapon *);
	void attack(Enemy *);
};

std::ostream & operator<<(std::ostream & os, Character const &);

