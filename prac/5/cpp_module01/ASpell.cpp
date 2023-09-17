#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell() {};

ASpell::ASpell(const ASpell& ref)
{
	static_cast<void>(ref);
}

ASpell& ASpell::operator=(const ASpell& ref)
{
	if (this != &ref)
	{
		this->name = ref.getName();
		this->effects = ref.getEffects();
	}
	return *this;
}

ASpell::~ASpell() {}

ASpell::ASpell(std::string _name, std::string _effects)
{
	this->name = _name;
	this->effects = _effects;
}

std::string	ASpell::getName() const
{
	return name;
}

std::string ASpell::getEffects() const
{
	return effects;
}

void	ASpell::launch(const ATarget& ref)
{
	ref.getHitBySpell(*this);
}
