#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() 
{
	std::cout << "Cure construct" << std::endl;
	this->type_ = "cure";
}

Cure::Cure(const Cure &ref)
{
	*this = ref;
}

Cure&	Cure::operator=(const Cure &ref)
{
	if (this != &ref)
	{
		std::cout << "assigning" << std::endl;
	}
	return (*this);
}

Cure::~Cure() {}

AMateria*	Cure::clone() const
{
	AMateria	*tmp = new Cure();
	return (tmp);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << \
	target.getName() << "\'s wounds *" << std::endl;
}
