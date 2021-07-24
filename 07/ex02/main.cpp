#include "Array.hpp"
#include <iostream>
#include <exception>

template <class T>
void printAll(Array<T> a)
{
	for (unsigned int i = 0; i < a.size(); i++)
	{
		std::cout << a[i];
		if (i < a.size() - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

void testValues(Array< Array<int> > & aa, unsigned int n1, unsigned int n2)
{
	for (unsigned int i = 0; i < n1; i++)
	{
		for (unsigned int j = 0; j < n2; j++)
		{
			try
			{
				std::cout << aa[i][j];
			}
			catch(std::exception const &)
			{
				std::cout << '?';
			}
			if (j < n2 - 1)
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
}

int main()
{
	Array<int> a(3); // Constructor(unsigned int)
	a[0] = 1; // operator[]
	a[1] = 2;
	a[2] = 3;

	Array<int> b(a); // Copy constructor
	Array<int> c; // Default constructor

	std::cout << "a: ";
	printAll(a);
	std::cout << "b: ";
	printAll(b);

	// operator[] (throwing exception)
	std::cout << "c[0]: ";
	try
	{
		std::cout << c[0];
	}
	catch (std::exception & e)
	{
		std::cout << "Out of bounds" << std::endl;
	}

	c = a;
	std::cout << "c[0]: " << c[0] << std::endl;

	// Other types ...
	// ... std::string
	Array<std::string> names(3);
	names[0] = "Pierre";
	names[1] = "Paul";
	names[2] = "Jacques";
	printAll(names);

	// ... Array<int>
	Array<int> d(1);
	d[0] = 4;
	Array< Array<int> > aa(2);
	aa[0] = a;
	aa[1] = d;
	testValues(aa, 2, 4);
}
