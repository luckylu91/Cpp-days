#pragma once
#include <string>

class Zombie {
	static std::string subjects[];
	static std::string actions[];
	static std::string target[];
	static std::string caps;
public:
	std::string type;
	std::string name;
	Zombie();
	Zombie(std::string type, std::string name);
	~Zombie();
	void advert();
	void announce();
};
