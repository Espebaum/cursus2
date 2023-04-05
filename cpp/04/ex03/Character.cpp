#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
	for (int i = 0; i < 4; ++i)
		this->slot[i] = NULL;
}

Character::Character(std::string name_)
{
	this->name = name_;
	for (int i = 0; i < 4; ++i)
		this->slot[i] = NULL;
}

Character::Character(const Character &ref) //깊은 복사
{
	*this = ref;
}

Character&  Character::operator=(const Character &ref) //깊은 복사
{
	if (this != &ref)
	{	
		this->name = ref.getName();
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
	if ((m->getType() != "cure" && m->getType() != "ice"))
	{
		std::cout << "Cannot equip " << m->getType() << \
		"It must be Cure or Ice" << std::endl;
		return ;
	}
	int	available_slot = 0;
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i] == NULL)
		{
			this->slot[i] = m;
			available_slot = i;
			break ;
		}
		if (i == 3)
		{
			std::cout << "Inventory is full!" << std::endl;
		}
	}
	std::cout << "Equipping " << available_slot << \
	"th slot " << m->getType() << std::endl;
}

void	Character::unequip(int idx)
{
	std::cout << "unequipping" << this->slot[idx]->getType() << \
	std::endl;
	this->slot[idx]->setType("");
}

void Character::use(int idx, ICharacter& target)
{
	std::cout << "num" << idx << " : ";
	if (idx > 3)
	{
		std::cout << "There's no slot after 4!" << std::endl;
		return ;
	}
	if (slot[idx] == NULL)
	{
		std::cout << "I cannot use that" << std::endl;
		return ;
	}
	this->slot[idx]->use(target);
}

Character::~Character() {}
