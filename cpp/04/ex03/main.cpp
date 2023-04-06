#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Color.hpp"

// void	leakcheck()
// {
// 	system("leaks -q ex03");
// }

int main()
{
	// atexit(leakcheck);

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// **** learning additional Materias ****
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	// **** testing OCCF functions ****
	// Character* you = new Character("Evaluator");
	// Character* bocal = new Character(*you);
	// Character* hero = new Character;
	// *hero = *you;

	AMateria* tmp;

	// **** creating Non-existing Materia ****
	// tmp = src->createMateria("non");
	// me->equip(tmp);

	tmp = src->createMateria("ice");
	me->equip(tmp);

	// **** equipping Materias ****
	// std::cout << "hero" << std::endl;
	// hero->equip(tmp);
	// std::cout << "you" << std::endl;
	// you->equip(tmp);
	// bocal->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	// **** equipping Materias ****
	// std::cout << "hero" << std::endl;
	// hero->equip(tmp);
	// std::cout << "you" << std::endl;
	// you->equip(tmp);
	// bocal->equip(tmp);

	// **** equipping additional Materias ****
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	
	// **** unequipping Materias ****
	// me->unequip(2);
	// me->unequip(3);


	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);

	// **** using Materias ****
	// hero->use(0, *bob);
	// hero->use(1, *bob);
	// me->use(2, *bob);
	// me->use(3, *bob);
	// me->use(4, *bob);
	
	delete bob;
	delete me;
	delete src;
	
	// **** deleting Characters and Materias ****
	// delete you;
	// delete bocal;
	// delete hero;
	
	return 0;
}
