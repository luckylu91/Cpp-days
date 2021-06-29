#include "Character.hpp"
#include "Enemy.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include <iostream>

int main()
{
	Character* me = new Character("Moi");
	std::cout << *me << std::endl;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	std::cout << std::endl;
	me->equip(pr);
	std::cout << *me << std::endl;
	me->equip(pf);
	me->attack(b);
	std::cout << std::endl;
	std::cout << *me;
	me->equip(pr);
	std::cout << *me << std::endl;
	me->attack(b);
	std::cout << std::endl;
	std::cout << *me << std::endl;
	me->attack(b);
	std::cout << std::endl;
	std::cout << *me << std::endl;
	delete me;
	delete pr;
	delete pf;
	return 0;
}
