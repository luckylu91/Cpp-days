#include "Zombie.hpp"
#include <iostream>
#include <cstdlib>

std::string Zombie::subjects[2] = {"I", "Me"};
std::string Zombie::actions[3] = {"eat", "consume", "want"};
std::string Zombie::target[3] = {"yoU", "braIn", "mEat"};

Zombie::Zombie(std::string name): name(name) {}

Zombie::~Zombie()
{
	std::cout << "The head of " << name << " exploded !" << std::endl;
}

void Zombie::announce()
{
	std::cout << "<" << name << "> Braiiiiinnnssss ..." << std::endl;
}

static std::string replaceAndRepeat(std::string target_string)
{
	static std::string caps = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int letter_repeat = rand() % 10 + 1;
	size_t pos = target_string.find_first_of(caps);

	if (pos != std::string::npos)
	{
		char c_to_repeat = tolower(target_string[pos]);
		return (target_string.replace(pos, 1, letter_repeat, c_to_repeat));
	}
	else
		return (target_string);
}

void Zombie::tease()
{
	int choice;

	std::cout << "<" << name << "> ";
	choice = rand() % 3;
	if (choice < 2)
		std::cout << Zombie::subjects[choice] << " ";
	else
		std::cout << name << " ";
	choice = rand() % 3;
	std::cout << Zombie::actions[choice] << " ";
	choice = rand() % 3;
	std::cout << replaceAndRepeat(Zombie::target[choice]);
	std::cout << " !" << std::endl;
}
