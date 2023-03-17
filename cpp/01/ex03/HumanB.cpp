#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->param = &weapon;
}

std::string HumanB::isArmed(std::string s) const
{
	if (s == "")
		return "Fists";
	return (s);
}

void HumanB::attack()
{
	std::cout << BOLDBLUE << this->name << BOLDWHITE << " attacks with their " << BOLDRED << isArmed(this->param->getType()) << std::endl;
}
