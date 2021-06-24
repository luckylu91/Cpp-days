#include "Pony.hpp"
#include <string>
#include <iostream>

Pony::Pony(std::string name): name(name) {}
Pony::~Pony() {
	std::cout << "Killing pony " << name << std::endl;
}
void Pony::doThings() const {
	std::cout << name << " is doing something amazing..." << std::endl;
}
