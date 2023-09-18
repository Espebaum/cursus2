#include "SpellBook.hpp"

void	SpellBook::learnSpell(ASpell* Spell)
{
	if (Spell)
		Spells.push_back(Spell);
}

void	SpellBook::forgetSpell(const std::string& SpellName)
{
	for (size_t i = 0; i < Spells.size(); i++)
	{
		if (SpellName == Spells[i]->getName())
			Spells.erase(Spells.begin() + i);
	}
}

ASpell*	SpellBook::createSpell(const std::string& SpellName)
{
	ASpell* MySpell = NULL;
	for (size_t i = 0; i < Spells.size(); i++)
	{
		if (SpellName == Spells[i]->getName())
			MySpell = Spells[i];
	}
	return MySpell;
}

