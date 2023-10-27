#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->param = NULL;
}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->param = &weapon;
}

// std::string HumanB::isArmed(std::string s) const
// {
// 	if (s.empty())
// 		return "Fists";
// 	return (s);
// }

std::string HumanB::isArmed(Weapon* param) const
{
	// std::cout << param;
	if (!param)
		return "Fists";
	return (param->getType());
}

void HumanB::attack()
{
	// this->param->setType("Cane");
	std::cout << BOLDBLUE << this->name << BOLDWHITE << " attacks with their " << BOLDRED << isArmed(this->param) << std::endl;
}
