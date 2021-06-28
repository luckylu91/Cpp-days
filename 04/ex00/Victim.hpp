#pragma once
#include <string>

class Victim
{
private:
void init();
protected:
	std::string name;
public:
	Victim(std::string name);
	Victim(Victim const &);
	~Victim();
	Victim & operator=(Victim const &);
	std::string getName() const;
	virtual void getPolymorphed() const;
};

std::ostream & operator<<(std::ostream & os, Victim const & victim);
