#include "iter.hpp"
#include <iostream>
#include <cstring>

template <typename T>
void printElem(T & elem)
{
	std::cout << elem << std::endl;
}

void isEven(int & i)
{
	if (i % 2 == 0)
		std::cout << "yes " << std::endl;
	else
		std::cout << "no " << std::endl;
}

int main()
{
	int		seq[] = {0, 1, 2, 3, 4, 5};
	char	fortytwo[] = "fortytwo";

	iter(seq, sizeof(seq) / sizeof(*seq), printElem);
	std::cout << std::endl;
	iter(fortytwo, std::strlen(fortytwo), printElem);
	std::cout << std::endl;
	iter(seq, sizeof(seq) / sizeof(*seq), isEven);
}
