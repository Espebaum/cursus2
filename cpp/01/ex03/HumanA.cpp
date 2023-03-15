#include "HumanA.hpp"

HumanA::HumanA()
{
	std::cout << "but no one appeared..." << std::endl ;
}

HumanA::HumanA(std::string name, Weapon weapon)
{
	this->name = name;
	this->param = weapon;
}


void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->param << std::endl;
}
