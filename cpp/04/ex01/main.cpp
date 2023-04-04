#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"

// void	leakcheck()
// {
// 	std::cout << BOLDWHITE << std::endl;
// 	system("leaks -q ex01");
// 	std::cout << std::endl;
// }

int main()
{
	// atexit(leakcheck);
	const	Animal *A[4];
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	for (int i = 0; i < 4; i++)
	{
		if (i % 2)
		{
			std::cout << BOLDYELLOW << i + 1 << "th Dog" << RESET << std::endl;
			A[i] = new Dog();
		}
		else
		{
			std::cout << BOLDMAGENTA << i + 1 << "th Cat" << RESET << std::endl;
			A[i] = new Cat();
		}
	}

	std::cout << BOLDWHITE << "--------------------------------------" << std::endl;
	std::cout << BOLDWHITE << "what is the type of j?" << std::endl;
	std::cout << "It's a " << j->getType() << "!!" << std::endl;
	std::cout << BOLDWHITE <<  "--------------------------------------" << std::endl;
	std::cout << BOLDWHITE << "what is j thinking about?" << std::endl;
	std::cout << j->getThink(50) << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	// std::cout << j->setThink(50, "FOOD") << std::endl; //j is const

	std::cout << "Seems like animals are leaving..." << std::endl;
	
	delete j; //should not create a leak
	delete i;

	for (int i = 0; i < 4; i++)
	{
		if (i % 2)
		{
			std::cout << BOLDYELLOW << i + 1 << "th Dog" << RESET << std::endl;
			delete	A[i];
		}
		else
		{
			std::cout << BOLDMAGENTA << i + 1 << "th Cat" << RESET << std::endl;
			delete	A[i];
		}
	}

	return 0;
}
