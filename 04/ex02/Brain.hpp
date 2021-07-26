#pragma once
#include <string>

class Brain
{
private:
	std::string ideas[100];
	void _copy(Brain const &);
public:
	Brain();
	Brain(Brain const &);
	~Brain();
	Brain & operator=(Brain const &);
};
