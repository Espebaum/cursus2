#include "AMateria.hpp"
// #include "ICharacter.hpp"

AMateria::AMateria()
{
	this->type_ = "None";
}

AMateria::~AMateria() {}

AMateria::AMateria(std::string const & type)
{
	this->type_ = type;
}

std::string const & AMateria::getType() const
{
	return (this->type_);
}

// void	AMateria::use(ICharacter& target)
// {
// 	std::cout << "using " << this->type_ << " to " << target.getName() << std::endl;
// }
