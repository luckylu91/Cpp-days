#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
	int n;

	if (argc < 2)
	{
		std::cout << "Usage ./\"exec_name\" [num_of_zombies=5]" << std::endl;
		n = 5;
	}
	else if (std::string(argv[1]).find_first_not_of("0123456789")
		== std::string::npos)
	{
		n = atoi(argv[1]);
	}
	else
	{
		std::cout << "First argument was not a positive ";
		std::cout << "integer (+ is not tolerated)" << std::endl;
		std::cout << "Usage ./\"exec_name\" [num_of_zombies=5]" << std::endl;
		return (1);
	}
	ZombieHorde zh(n);
	std::cout << "A horde of size " << n << " was created :" << std::endl;
	zh.announce();
	std::cout << std::endl;
	std::cout << "End of program" << std::endl;
	return (0);
}
