#include "dog.hpp"

dog::dog()
{
	std::cout << "It's a dog!" << std::endl;
	std::cout << "bow-Wow!(HI!)" << std::endl;
	this->type = "dog";
}

dog::~dog()
{
	std::cout << "bow-Wow(I'm leaving!)" << std::endl;
}

dog::dog(const dog &ref)
{
	std::cout << "copying constructor operating" << std::endl;
	*this = ref;
}

dog&	dog::operator=(const dog &ref)
{
	std::cout << "assigning" << std::endl;
	if (this != &ref)
	{
		this->type = ref.type;
	}
	return (*this);
}

void	