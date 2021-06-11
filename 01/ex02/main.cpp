#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>
#include <cstdlib>

void stack_steaks()
{
	Zombie z_stack("stack_zombie", "Steaky");

	std::cout << "We inside another function, named stack_steak()" << std::endl;
	std::cout << "Please welcome Steaky, the stack zombie !" << std::endl;
	z_stack.advert();
	std::cout << "Stop this nonsens Steaky..." << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "\t";
		z_stack.announce();
	}
	std::cout << "Watch out Steaky, we are near the end of your function !" << std::endl;
}

int main()
{
	ZombieEvent ze;
	Zombie *z_lucas, *z_rand[3];

	srand(time(NULL));
	std::cout << "Crating zombie named Lucas with newZombie()";
	std::cout << " (default type)" << std::endl;
	z_lucas = ze.newZombie("Lucas");
	std::cout << "z_lucas.advert()" << std::endl;
	z_lucas->advert();
	std::cout << "z_lucas.anounce() <--- random" << std::endl;
	z_lucas->announce();
	std::cout << std::endl;
	std::cout << "Changing ZombieEvent's type to walking_dead_zombie" << std::endl;
	ze.setZombieType("walking_dead_zombie");
	std::cout << "Crating random zombies (they will announce by themself)" << std::endl;
	for (int i = 0; i < 3 ; i++)
		z_rand[i] = ze.randomChump();
	std::cout << std::endl;
	std::cout << "No need for those suckers !" << std::endl;
	delete z_lucas;
	for (int i = 0; i < 3 ; i++)
		delete z_rand[i];
	std::cout << std::endl;
	stack_steaks();
	std::cout << "How awfull..." << std::endl;
	return 0;
}
