#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() 
{
	std::cout << "ice construct" << std::endl;
	this->type_ = "ice";
}

Ice::Ice(const Ice &ref)
{
	*this = ref;
}

Ice&	Ice::operator=(const Ice &ref)
{
	if (this != &ref)
	{
		std::cout << "assigning" << std::endl;
	}
	return (*this);
}

Ice::~Ice() {}

AMateria*	Ice::clone() const
{
	AMateria	*tmp = new Ice();
	return (tmp);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << \
	target.getName() << " *" << std::endl;
}
