#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "-> Creating Animal" << std::endl;
	const Animal *meta = new Animal();
	std::cout << "-> Creating Dog" << std::endl;
	const Animal *j = new Dog();
	std::cout << "-> Creating Cat" << std::endl;
	const Animal *i = new Cat();
	std::cout << std::endl;

	std::cout << j->getType() << " : ";
	j->makeSound();
	std::cout << i->getType() << " : ";
	i->makeSound();
	std::cout << "Animal : ";
	meta->makeSound();

	std::cout << "-> Deleting" << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;

	std::cout << "-> Creating WrongAnimal" << std::endl;
	const WrongAnimal *metaW = new WrongAnimal();
	std::cout << "-> Creating WrongCat" << std::endl;
	const WrongAnimal *iW = new WrongCat();
	std::cout << std::endl;

	std::cout << iW->getType() << " : ";
	iW->makeSound();
	std::cout << "WrongAnimal : ";
	metaW->makeSound();
	
	std::cout << "-> Deleting" << std::endl;
	delete metaW;
	delete iW;
}