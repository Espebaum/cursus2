#include "Animal.hpp"
#include "Brain.hpp"

Animal::Animal()
{
	std::cout << BOLDGREEN;
	std::cout << "Here's Something looks like Animal!" << std::endl;
	std::cout << std::endl;
	
	this->type = "Something looks like Animal";
}

Animal::~Animal()
{
	std::cout << BOLDGREEN;
	std::cout << this->type << " is leaving" << std::endl;
	std::cout << std::endl;
}

Animal::Animal(const Animal &ref)
{
	std::cout << BOLDGREEN;
	std::cout << "copying constructor operating" << std::endl;
	*this = ref;
}

Animal&	Animal::operator=(const Animal &ref)
{
	std::cout << BOLDGREEN;
	std::cout << "assigning" << std::endl;
	if (this != &ref)
	{
		this->type = ref.type;
	}
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << BOLDGREEN;
	std::cout << "I can hear a sound of Animal" << std::endl;
	std::cout << std::endl;
}

std::string	Animal::getType() const
{
	std::cout << BOLDGREEN;
	return (this->type);
}

std::string Animal::getThink(int i) const 
{
	i = 0;
	return ("I don't have any idea");
}

void	Animal::setThink(int i, std::string content)
{
	i = 0;
	std::cout << "I don't have any idea about " << \
	content << "\"" << std::endl;
}
