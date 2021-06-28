#pragma once
#include "Victim.hpp"
#include <string>

class Peon : public Victim
{
private:
	void init();
public:
	Peon(std::string name);
	Peon(Peon const &);
	~Peon();
	Peon & operator=(Peon const &);
	virtual void getPolymorphed() const;
};
