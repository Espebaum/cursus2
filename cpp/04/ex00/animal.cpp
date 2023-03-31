#include "animal.hpp"

animal::animal()
{
	std::cout << "Here's Something looks like Animal!" << std::endl;
	this->type = "Something looks like Animal";
}

animal::~animal()
{
	std::cout << this->type << "is leaving" << std::endl;
}

animal::animal(const animal &ref)
{
	std::cout << "copying constructor operating" << std::endl;
	*this = ref;
}

animal&	animal::operator=(const animal &ref)
{
	std::cout << "assigning" << std::endl;
	if (this != &ref)
	{
		this->type = ref.type;
	}
	return (*this);
}

// void	animal::makeSound()
// {
// 	std::cout << "I can hear a sound of animal" << std::endl;
// }
