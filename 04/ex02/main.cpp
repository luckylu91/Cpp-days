#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	{
		const Animal *array[2];
		std::cout << "-> Creating Dog" << std::endl;
		array[0] = new Dog();
		std::cout << "-> Creating Cat" << std::endl;
		array[1] = new Cat();
		std::cout << std::endl;

		std::cout << "-> Deleting both" << std::endl;
		for (int i = 0; i < 2; i++)
			delete array[i];
	}

	std::cout << std::endl;

	{
		std::cout << "-> Creating Cat" << std::endl;
		Cat cat1;
		std::cout << "-> Copying Cat" << std::endl;
		Cat cat2(cat1);
		std::cout << "-> Creating Cat" << std::endl;
		Cat cat3;
		std::cout << "-> Assigning Cat" << std::endl;
		cat3 = cat1;

		std::cout << "-> End of Scope (destruction)" << std::endl;
	}
}
