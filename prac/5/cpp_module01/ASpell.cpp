#include "ASpell.hpp"

std::string ASpell::getName() const
{
	return name;
}

std::string ASpell::getEffects() const
{
	return effects;
}

ASpell::ASpell(const std::string& _name, const std::string& _effects) :
	name(_name), effects(_effects) {}

void	ASpell::launch(const ATarget& ref) const
{
	ref.getHitBySpell(*this);
}
