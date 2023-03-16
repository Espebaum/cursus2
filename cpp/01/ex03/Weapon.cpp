#include "Weapon.hpp"

Weapon::Weapon()
{
	this->type = "Fists";
}

Weapon::Weapon(std::string weapon)
{
	this->type = weapon;
}

Weapon::~Weapon() {}

std::string	Weapon::getType() const
{
	return (this->type);
}

void	Weapon::setType(std::string weapon)
{
	this->type = weapon;
}
