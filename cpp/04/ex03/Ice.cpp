#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Color.hpp"

Ice::Ice() 
{
	// std::cout << BOLDGREEN << std::endl;
	// std::cout << "ice construct" << std::endl;
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

Ice::~Ice()
{
	// std::cout << BOLDRED << std::endl;
	// std::cout << "Vanishing " << BOLDBLUE << "Ice" \
	// << BOLDRED << " power" << std::endl;
}

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
