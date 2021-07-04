#pragma once
#include <string>

class Zombie
{
	static std::string subjects[];
	static std::string actions[];
	static std::string target[];
	static std::string caps;
	std::string name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void setName(std::string const &);
	void announce();
	void tease();
};
