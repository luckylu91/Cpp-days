#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
	Span s0(0);
	Span s3(3);
	int s3Numbers[] = {1, 2, 3, 4};
	Span sa(100000), sb(100000);
	std::vector<int> vect;
	Span sc(6);
	// Shortest span : 2
	// Longest span : 15
	int scNumbers[] = {3, 5, 9, 12, 15, 18};
	Span sd(20000);

	// Initializing vector
	for (int i = 0; i < 100000; i++) {
		vect.push_back(i);
	}

	try
	{
		std::cout << "Adding 1" << std::endl;
		s0.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "Adding Array {1, 2, 3, 4}" << std::endl;
		s3.addNumbers(s3Numbers, s3Numbers + sizeof(s3Numbers) / sizeof(*s3Numbers));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	Span s4(s3);
	std::cout << "Copy of " << s3 << " : " << s4 << std::endl;
	std::cout << std::endl;

	std::cout << "Adding 100000 numbers one by one (addNumber)" << std::endl;
	for (int i = 0; i < 100000; i++)
	{
		sa.addNumber(i);
	}
	std::cout << std::endl;

	std::cout << "Adding 100000 numbers with one call (addNumbers)" << std::endl;
	sb.addNumbers(vect.begin(), vect.end());
	std::cout << std::endl;


	sc.addNumbers(scNumbers, scNumbers + sizeof(scNumbers) / sizeof(*scNumbers));
	std::cout << "Span : " << sc << std::endl;
	std::cout << "\tShortest span : " << sc.shortestSpan() << std::endl;
	std::cout << "\tLongest span : " << sc.longestSpan() << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 20000; i++)
	{
		sd.addNumber(i);
	}
	std::cout << "Span " << sd << std::endl;
	std::cout << "\tShortest span : " << sd.shortestSpan() << std::endl;
	std::cout << "\tLongest span : " << sd.longestSpan() << std::endl;
}
