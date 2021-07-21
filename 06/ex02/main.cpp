#include <random>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int r = rand() % 3;
	switch (r)
	{
		case 0:
			std::cout << "Generating A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generating B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generating C" << std::endl;
			return new C();
	}
	return NULL;
}

void identify(Base *p)
{
	A * pA = dynamic_cast<A *>(p);
	B * pB = dynamic_cast<B *>(p);
	C * pC = dynamic_cast<C *>(p);

	if (pA)
		std::cout << "A" << std::endl;
	else if (pB)
		std::cout << "B" << std::endl;
	else if (pC)
		std::cout << "C" << std::endl;
	else
		std::cout << "NULL" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A & pA = dynamic_cast<A &>(p);
		(void)pA;
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::bad_cast &bc) {}
	try
	{
		B & pB = dynamic_cast<B &>(p);
		(void)pB;
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::bad_cast &bc) {}
	try
	{
		C & pC = dynamic_cast<C &>(p);
		(void)pC;
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::bad_cast &bc) {}
}

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Base *p = generate();
		identify(p);
		identify(*p);
		delete p;
	}
	return 0;
}
