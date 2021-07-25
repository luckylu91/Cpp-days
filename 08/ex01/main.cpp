#include "Span.hpp"
#include <iostream>

int main()
{
	Span s0(0);
	Span s3(3);
	int s3Numbers[] = {1, 2, 3, 4};

	try
	{
		s0.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		s3.addNumbers(s3Numbers, s3Numbers + sizeof(s3Numbers) / sizeof(*s3Numbers));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


}
