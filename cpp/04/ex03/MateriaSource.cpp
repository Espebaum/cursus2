#include "MateriaSource.hpp"
#include "Color.hpp"

// Applying OCCF
MateriaSource::MateriaSource() 
{
	for (int i = 0; i < 4; i++)
		this->power[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &ref)
{
	*this = ref;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &ref)
{
	if (this != &ref)
	{
		std::cout << "assigning operation" << std::endl;
	}
	return (*this);
}

MateriaSource::~MateriaSource() 
{
	for (int i = 0; i < 4; i++)
	{
		if (this->power[i] != NULL)
		{
			delete this->power[i];
			this->power[i] = NULL;
		}
	}
}

// define virtual functions
void MateriaSource::learnMateria(AMateria *source)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->power[i] == NULL)
		{
			this->power[i] = source;
			break ;
		}
		if (i == 3)
		{
			std::cout << BOLDRED << std::endl;
			std::cout << "Power Source is full" << RESET << std::endl;
			delete	source;
			return ;
		}
	}
	// for (int i = 0; i < 4; i++)
	// {
	// 	std::cout << BOLDMAGENTA << std::endl;
	// 	if (this->power[i] != NULL)
	// 		std::cout << i << "th power slot is " << this->power[i]->getType() << std::endl;
	// 	else
	// 		std::cout << i << "th power slot is EMPTY" << std::endl;
	// 	std::cout << RESET;
	// }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (type != "ice" && type != "cure")
	{
		std::cout << "I can't create that" << std::endl;
		return (0);
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->power[i] != NULL && this->power[i]->getType() == type)
			return (power[i]);
	}
	return (0);
}
