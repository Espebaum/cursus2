#include "Character.hpp"
#include "AMateria.hpp"
#include "Color.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
		this->slot[i] = NULL;
}

Character::Character(std::string name_)
{
	this->name = name_;
	for (int i = 0; i < 4; i++)
		this->slot[i] = NULL;
}

Character::Character(const Character &ref)
{
	std::cout << BOLDYELLOW << "Copying Character" <<std::endl;
	this->name = ref.getName();
	for (int i = 0; i < 4; i++)
	{
		AMateria	*copy;
		if (ref.slot[i] != NULL)
			copy = ref.slot[i]->clone();
		else
			copy = NULL;
		this->slot[i] = copy;
	}
}

Character&  Character::operator=(const Character &ref)
{
	std::cout << BOLDYELLOW << "Assigning Character" <<std::endl;
	if (this != &ref)
	{	
		this->name = ref.getName();
		for (int i = 0; i < 4; i++)
		{
			AMateria	*copy;
			if (ref.slot[i] != NULL)
				copy = ref.slot[i]->clone();
			else
				copy = NULL;
			this->slot[i] = copy;
		}
	}
	return (*this);
}

std::string const& Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Is it Ice or Cure?" << std::endl;
		return ;
	}
	int	available_slot = 0;
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i] == NULL)
		{
			AMateria	*item = m->clone();
			this->slot[i] = item;
			available_slot = i;
			break ;
		}
		if (i == 3)
		{
			std::cout << BOLDRED;
			std::cout << "Inventory is full!" << std::endl;
			return ;
		}
	}

	// std::cout << "Equipping " << available_slot << \
	// "th slot " << m->getType() << std::endl;
	
	// for (int i = 0; i < 4; i++)
	// {
	// 	std::cout << BOLDWHITE;
	// 	if (this->slot[i] != NULL)
	// 		std::cout << "My " << i << "th slot is " << \
	// 		this->slot[i]->getType() << std::endl;
	// 	else
	// 		std::cout << "My " << i << "th slot is empty" << std::endl;
	// }
	// std::cout << RESET;
}

void	Character::unequip(int idx)
{
	if (idx > 3)
	{
		std::cout << "I only have 4 slot!" << std::endl; 
		return ;
	}
	std::cout << BOLDCYAN;
	std::cout << "unequipping " << idx << "th slot (" \
	<< this->slot[idx]->getType() << ")" << std::endl;
	delete this->slot[idx];
	this->slot[idx] = NULL;

	// for (int i = 0; i < 4; i++)
	// {
	// 	std::cout << BOLDWHITE;
	// 	if (this->slot[i] != NULL)
	// 		std::cout << "My " << i << "th slot is " << \
	// 		this->slot[i]->getType() << std::endl;
	// 	else
	// 		std::cout << "My " << i << "th slot is empty" << std::endl;
	// }
	// std::cout << RESET;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3)
	{
		std::cout << "There's no slot after 4!" << std::endl;
		return ;
	}
	if (this->slot[idx] == NULL)
	{
		std::cout << "There's no Materia in my slot!" << std::endl;
		return ;
	}
	this->slot[idx]->use(target);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete this->slot[i];
		this->slot[i] = NULL;
	}
}
