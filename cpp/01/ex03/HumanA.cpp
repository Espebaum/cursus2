#include "HumanA.hpp"

HumanA::HumanA()
{
	std::cout << "but no one appeared..." << std::endl ;
}

HumanA::~HumanA() {}

HumanA::HumanA(std::string name, Weapon &weapon)
{
	this->name = name;
	this->param = &weapon;
}

void HumanA::attack()
{
	std::cout << BOLDBLUE << this->name << BOLDWHITE << " attacks with their " << BOLDRED << this->param->getType() << std::endl;
}
