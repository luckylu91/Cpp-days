#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
	std::cout << "A horde of size 8 zombies all named octave will be created :" << std::endl;
	ZombieHorde zh(8, "Octave");
	std::cout << "Announce :" << std::endl;
	zh.announce();
	std::cout << "Tease (pour le fun) :" << std::endl;
	zh.tease();
	std::cout << "Deletion is automatic via ZombieHorde's desctuctor" << std::endl;
	return (0);
}
