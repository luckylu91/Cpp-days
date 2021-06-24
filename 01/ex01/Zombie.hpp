#pragma once
#include <string>

class Zombie {
	static std::string subjects[];
	static std::string actions[];
	static std::string target[];
	static std::string caps;
public:
	std::string name;
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce();
	void tease();
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
