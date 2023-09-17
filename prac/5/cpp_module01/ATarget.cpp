#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget() {}

ATarget::ATarget(const ATarget& ref) { static_cast<void>(ref); }

ATarget& ATarget::operator=(const ATarget& ref)
{
	if (this != &ref)
	{
		this->type = ref.getType();
	}
	return *this;
}

ATarget::~ATarget() {}

ATarget::ATarget(std::string _type)
{
	this->type = _type;
}

const std::string& ATarget::getType() const
{
	return type;
}

void ATarget::getHitBySpell(const ASpell& ref) const
{
	std::cout << getType() << " has been " << ref.getEffects() << "!" << std::endl;
}

