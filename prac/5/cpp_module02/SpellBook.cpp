#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {}

SpellBook::SpellBook(const SpellBook& ref)
{
	*this = ref;
}

SpellBook& SpellBook::operator=(const SpellBook& ref)
{
	static_cast<void>(ref);
	return *this;
}

void SpellBook::learnSpell(ASpell* Spell)
{
	if (Spell)
		Book.push_back(Spell);
}

void SpellBook::forgetSpell(std::string const &SpellName)
{
	for (size_t i = 0; i < Book.size(); i++)
	{
		if (SpellName == Book[i]->getName())
			Book.erase(Book.begin() + i);	
	}
}

ASpell* SpellBook::createSpell(std::string const &SpellName)
{
	ASpell* newSpell = NULL;
	for (size_t i = 0; i < Book.size(); i++)
	{
		if (SpellName == Book[i]->getName())
			newSpell = Book[i];  	
	}
	return newSpell;
}
