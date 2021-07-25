#include "functions.hpp"
#include <iostream>

template <typename T>
void testOne(T & a, T & b)
{
	std::cout << "min(" << a << ", " << b << ") = " << min(a, b) << std::endl;
	std::cout << "max(" << a << ", " << b << ") = " << max(a, b) << std::endl;
	std::cout << "a = " << a << ";\tb = " << b << ";" << std::endl;
	std::cout << "Swaping..." << std::endl;
	swap(a, b);
	std::cout << "a = " << a << ";\tb = " << b << ";" << std::endl << std::endl;
}

int main()
{
	int ia = 0, ib = 1;
	char ca = 'A', cb = 'B';
	std::string sa = "abcd", sb = "zyxw";

	testOne<int>(ia, ib);
	testOne<char>(ca, cb);
	testOne<std::string>(sa, sb);
}
