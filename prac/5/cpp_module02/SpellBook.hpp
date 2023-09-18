#pragma once

#include "ASpell.hpp"
#include <vector>

class ASpell;

class SpellBook
{
	private:
		std::vector<ASpell*> Spells;
		SpellBook(const SpellBook& ref) { *this = ref; }
		SpellBook& operator=(const SpellBook& ref) { static_cast<void>(ref); return *this; }
	public:
		SpellBook() {}
		~SpellBook() {}

		void learnSpell(ASpell* Spell);
		void forgetSpell(const std::string& SpellName);
		ASpell* createSpell(const std::string& SpellName);
};
