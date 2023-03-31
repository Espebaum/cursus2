#include "cat.hpp"

cat::cat()
{
	std::cout << "It's a cat!" << std::endl;
	std::cout << "Meow!" << std::endl;
	this->type = "cat";
}

cat::~cat()
{
	std::cout << "Meow(I'm leaving!)" << std::endl;
}

cat::cat(const cat &ref)
{
	std::cout << "copying constructor operating" << std::endl;
	*this = ref;
}

cat&	cat::operator=(const cat &ref)
{
	std::cout << "assigning" << std::endl;
	if (this != &ref)
	{
		this->type = ref.type;
	}
	return (*this);
}
