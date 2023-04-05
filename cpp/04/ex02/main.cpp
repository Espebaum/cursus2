#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"

void	leakcheck()
{
	std::cout << BOLDWHITE << std::endl;
	system("leaks -q ex02");
	std::cout << std::endl;
}

int main()
{
	atexit(leakcheck);
	// Animal	ani; // it occurs error because Animal is Abstract Class
	Animal	*doggy_ptr;
	Animal	*kitty_ptr;
	Dog		doggy;
	Cat		kitty;
	doggy_ptr = &doggy;
	kitty_ptr = &kitty;

	std::cout << doggy.getThink(1) << std::endl;
	std::cout << kitty.getThink(1) << std::endl;
	std::cout << std::endl;

	doggy.setThink(1, "MEOW?");
	doggy_ptr->setThink(2, "POINTER??");
	
	kitty.setThink(1, "BARK?");
	kitty_ptr->setThink(2, "POINTER??");
		
	std::cout << doggy.getThink(1) << std::endl;
	std::cout << doggy_ptr->getThink(2) << std::endl;
	std::cout << kitty.getThink(1) << std::endl;
	std::cout << kitty_ptr->getThink(2) << std::endl;
	std::cout << std::endl;

	return 0;
}
