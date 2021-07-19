#include "Converter.hpp"
#include <iostream>

void printUsage()
{
	std::cerr << "Usage : ./convert arg" << std::endl;
	std::cerr << "\targ: string representation of a litteral" << std::endl;
}

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printUsage();
		return 1;
	}
	Converter conv;
	conv.fromString(argv[1]);
	conv.show();
	return 0;
}

