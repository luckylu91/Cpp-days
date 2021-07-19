#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char const *argv[])
{
	if (argc < 2)
		return 1;
	std::string str(argv[1]);
	std::stringstream ss(str);
	char c;
	int i;
	float f;
	double d;
	ss >> c;
	if (ss)
		std::cout << "Success : c = " << c << std::endl;
	else
		std::cout << "Failure : c" << std::endl;
	ss.clear();
	ss.str(str);
	ss >> i;
	if (ss)
		std::cout << "Success : i = " << i << std::endl;
	else
		std::cout << "Failure : i" << std::endl;
	ss.clear();
	ss.str(str);
	ss >> f;
	if (ss)
		std::cout << "Success : f = " << f << std::endl;
	else
		std::cout << "Failure : f" << std::endl;
	ss.clear();
	ss.str(str);
	ss >> d;
	if (ss)
		std::cout << "Success : d = " << d << std::endl;
	else
		std::cout << "Failure : d" << std::endl;
	ss.clear();
	return 0;
}
