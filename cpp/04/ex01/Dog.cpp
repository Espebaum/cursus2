#include "Dog.hpp"

Dog::Dog()
{
	std::cout << BOLDYELLOW;
	std::cout << "It's a Dog!" << std::endl;
	std::cout << "bow-Wow!(HI!)" << std::endl;
	std::cout << std::endl;

	this->type = "Dog";
}

Dog::~Dog()
{
	std::cout << BOLDYELLOW;
	std::cout << "bow-Wow!!(I'm leaving!)" << std::endl;
	std::cout << std::endl;
}

Dog::Dog(const Dog &ref)
{
	std::cout << "copying constructor operating" << std::endl;
	*this = ref;
}

Dog&	Dog::operator=(const Dog &ref)
{
	std::cout << "assigning" << std::endl;
	if (this != &ref)
	{
		this->type = ref.type;
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << BOLDYELLOW;
	std::cout << "bow-Wow!! bow-Wow!!" << std::endl;
	std::cout << std::endl;
}
