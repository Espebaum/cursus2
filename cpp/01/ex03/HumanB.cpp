#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}


void HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->Weapon << std::endl;
}
