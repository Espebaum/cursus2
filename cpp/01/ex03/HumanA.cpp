#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : param(weapon), name(name) {}

HumanA::~HumanA() {}

void HumanA::attack()
{
	std::cout << BOLDBLUE << this->name << BOLDWHITE << " attacks with their " << BOLDRED << this->param.getType() << std::endl;
}
