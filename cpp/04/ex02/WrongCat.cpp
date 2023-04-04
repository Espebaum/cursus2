#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << BOLDBLUE;
	std::cout << "Hey, Is that a cat?" << std::endl;
	std::cout << "Meow?(Hi?)" << std::endl;
	std::cout << std::endl;

	this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << BOLDBLUE;
	std::cout << "Meow?? (I'm leaving?)" << std::endl;
	std::cout << std::endl;
}

WrongCat::WrongCat(const WrongCat &ref)
{
	std::cout << BOLDBLUE;
	std::cout << "copying constructor operating" << std::endl;
	*this = ref;
}

WrongCat&	WrongCat::operator=(const WrongCat &ref)
{
	std::cout << BOLDBLUE;
	std::cout << "assigning" << std::endl;
	if (this != &ref)
	{
		this->type = ref.type;
	}
	return (*this);
}

void	WrongCat::makeSound()
{
	std::cout << BOLDBLUE;
	std::cout << "Meow?? Meow??" << std::endl;
	std::cout << std::endl;
}
