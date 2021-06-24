#include <iostream>

int main()
{
	std::string s("HI THIS IS BRAIN");
	std::string *sPtr = &s;
	std::string &sRef = s;

	std::cout << &s << std::endl;
	std::cout << sPtr << std::endl;
	std::cout << &sRef << std::endl;

	std::cout << *sPtr << std::endl;
	std::cout << sRef << std::endl;
}
