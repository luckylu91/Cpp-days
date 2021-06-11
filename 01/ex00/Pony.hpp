#pragma once
#include <string>
#include <iostream>

class Pony {
	std::string name;
public:
	Pony(std::string);
	void doThings() const;
	~Pony();
};
