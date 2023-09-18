#include "ATarget.hpp"

const std::string& ATarget::getType() const
{
	return type;
}

ATarget::ATarget(const std::string& _type) :
	type(_type) {}

void	ATarget::getHitBySpell(const ASpell& ref) const
{
	std::cout << type << " has been " << ref.getEffects() << "!" << std::endl;
}
