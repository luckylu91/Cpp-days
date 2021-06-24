#include "Zombie.hpp"
#include <iostream>
#include <cstdlib>

void stack_steaks()
{
	Zombie z_stack("Steaky");

	std::cout << "We inside another function, named stack_steak()" << std::endl;
	std::cout << "Please welcome Steaky, the stack zombie !" << std::endl;
	z_stack.tease();
	std::cout << "Stop this nonsens Steaky..." << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "\t";
		z_stack.tease();
	}
	std::cout << "Watch out Steaky, this is the limit of your scope !" << std::endl;
}

int main()
{
	Zombie *z_lucas;

	srand(time(NULL));
	std::cout << "Crating zombie named Lucas with newZombie()" << std::endl;
	z_lucas = newZombie("Lucas");
	std::cout << "* ZLucas.anounce() *" << std::endl;
	z_lucas->announce();
	std::cout << "* delete ZLucas * :(" << std::endl;
	delete z_lucas;
	std::cout << std::endl;
	stack_steaks();
	std::cout << "How awfull..." << std::endl;
	return 0;
}
