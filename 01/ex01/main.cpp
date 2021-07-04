#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
	std::cout << "A horde of size 8 zombies all named octave will be created :" << std::endl;
	Zombie* horde = zombieHorde(8, "Octave");
	std::cout << "Announce :" << std::endl;
	for (int i = 0; i < 8; i++)
		horde[i].announce();
	std::cout << "Tease (pour le fun) :" << std::endl;
	for (int i = 0; i < 8; i++)
		horde[i].tease();
	std::cout << "Deletion via delete []..." << std::endl;
	delete [] horde;
	std::cout << "...Done !" << std::endl;
	return (0);
}
