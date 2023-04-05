#include "Cat.hpp"

Cat::Cat()
{
	std::cout << BOLDMAGENTA;
	std::cout << "It's a Cat!" << std::endl;
	std::cout << "Meow!(Hi!)" << std::endl;
	std::cout << std::endl;

	this->type = "Cat";
	this->head = new Brain();
}

Cat::~Cat()
{
	std::cout << BOLDMAGENTA;
	delete head;

	std::cout << "Meow!!(I'm leaving!)" << std::endl;
	std::cout << std::endl;
}

Cat::Cat(const Cat &ref)
{
	std::cout << BOLDMAGENTA;
	std::cout << "copying constructor operating" << std::endl;
	*this = ref;
}

Cat&	Cat::operator=(const Cat &ref)
{
	std::cout << BOLDMAGENTA;
	std::cout << "assigning" << std::endl;
	if (this != &ref)
	{
		this->type = ref.type;
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << BOLDMAGENTA;
	std::cout << "Meow~ Meow~" << std::endl;
	std::cout << std::endl;
}

std::string	Cat::getType() const
{
	std::cout << BOLDMAGENTA;
	return (this->type);
}

std::string Cat::getThink(int i) const
{
	return (this->head->getIdea(i));
}

void	Cat::setThink(int i, std::string content)
{
	this->head->setIdea(i, content);
}
