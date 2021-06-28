#pragma once
#include <string>

class Victim
{
private:
	std::string name;
public:
	Victim(std::string name);
	~Victim();
	std::string getName() const;
	virtual void getPolymorphed() const;
};

std::ostream & operator<<(std::ostream const & os, Victim const & victim);
