#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << BOLDRED;
	std::cout << "Hey, Is that an Animal?" << std::endl;
	std::cout << std::endl;
	
	this->type = "Something does not look like Animal";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << BOLDRED;
	std::cout << this->type << " is leaving" << std::endl;
	std::cout << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref)
{
	std::cout << "copying constructor operating" << std::endl;
	*this = ref;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &ref)
{
	std::cout << "assigning" << std::endl;
	if (this != &ref)
	{
		this->type = ref.type;
	}
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << BOLDRED;
	std::cout << "I can hear a sound of something" << std::endl;
	std::cout << std::endl;
}

std::string	WrongAnimal::getType() const
{
	std::cout << BOLDWHITE;
	return (this->type);
}
