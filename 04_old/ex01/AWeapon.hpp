#pragma once
#include <string>

class AWeapon
{
protected:
	std::string	name;
	int			apcost;
	int			damage;
public:
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon(AWeapon const &);
	virtual ~AWeapon();
	AWeapon & operator=(AWeapon const &);
	std::string const & getName() const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;
};
