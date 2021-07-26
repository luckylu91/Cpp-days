#pragma once
#include <string>
#include <iostream>
#include "Victim.hpp"

class Sorcerer
{
private:
	std::string name;
	std::string title;
	void init();
public:
	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer const &);
	~Sorcerer();
	Sorcerer & operator=(Sorcerer const &);
	std::string getName() const;
	std::string getTitle() const;
	void polymorph(Victim const &) const;
};

std::ostream & operator<<(std::ostream & os, Sorcerer const & sorcerer);
