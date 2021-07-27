#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
		IMateriaSource * src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter * alice = new Character("alice");
		AMateria * tmp;
		tmp = src->createMateria("ice");
		alice->equip(tmp);
		tmp = src->createMateria("cure");
		alice->equip(tmp);

		ICharacter* bob = new Character("bob");
		alice->use(0, *bob);
		alice->use(1, *bob);

		tmp = new Ice();
		alice->equip(tmp);
		alice->unequip(2); // <- stupid

		std::cout << "-> Deleting src" << std::endl;
		delete src;
		std::cout << "-> Deleting bob" << std::endl;
		delete bob;
		std::cout << "-> Deleting alice" << std::endl;
		delete alice;
		delete tmp; // <- previously unequiped, so no error (and Ice desructor called)
	}

	std::cout << std::endl;

	{
		Character chantale("chantale");
		chantale.equip(new Ice());

		std::cout << "-> Copy constructor on chantale" << std::endl;
		Character chantale_copy(chantale);

		Character denis("denis");
		denis.equip(new Cure());
		std::cout << "-> Assignment of chantal on denis" << std::endl;
		denis = chantale;

		std::cout << "-> End of scope" << std::endl;
	}

	return 0;
}
