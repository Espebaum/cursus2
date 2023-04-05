#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"

// void	leakcheck()
// {
// 	std::cout << BOLDWHITE << std::endl;
// 	system("leaks -q ex00");
// 	std::cout << std::endl;
// }

int main()
{
	// atexit(leakcheck);
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	// std::cout<<BOLDCYAN<<"Test"<<std::endl;
	// const Animal	ani;
	// const Animal	ani2;
	// ani2 = ani; //there's no overloaded function assigning const function to const function
	// std::cout<<BOLDCYAN<<"test"<<RESET<<std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;

	i->makeSound();	//will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal*	WrongMeta = new WrongAnimal(); 
	const WrongAnimal*	k = new WrongCat();
	
	k->makeSound();
	WrongMeta->makeSound();

	delete	i;	//will output the cat sound!
	delete	j;
	delete	meta;
	delete	k;
	delete	WrongMeta;

	return 0;
}
