#include "easyfind.hpp"
#include <list>
#include <vector>
#include <iostream>

template<typename T>
void printContainer(T & cont)
{
	typename T::const_iterator it = cont.begin();
	while (it != cont.end())
	{
		std::cout << *it;
		++it;
		if (it != cont.end())
			std::cout << ", ";
	}
}

template<typename T>
void testFind(std::string const & containerTypeName, T & cont, int i)
{
	std::cout << "(" << containerTypeName << ") ";
	printContainer(cont);
	std::cout << ": contains " << i << " ? ";
	std::cout << (easyfind(cont, i) ? "yes" : "no") << std::endl;
}

int main()
{
	int values[] = {1, 2, 5, 6, 7};
	std::vector<int> v(values, values + sizeof(values) / sizeof(int));
	std::list<int> l(v.begin(), v.end());

	testFind("vector", v, 1);
	testFind("vector", v, 3);
	testFind("list", l, 5);
	testFind("list", l, 8);
}
