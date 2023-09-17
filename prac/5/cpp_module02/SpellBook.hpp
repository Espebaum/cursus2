#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "ASpell.hpp"

class SpellBook
{
	private:
		std::vector<ASpell*> Book;
		SpellBook(const SpellBook& ref);
		SpellBook& operator=(const SpellBook& ref);
	public:
		~SpellBook();
		SpellBook();
		
		void learnSpell(ASpell* Spell);
		void forgetSpell(std::string const &ref);
		ASpell* createSpell(std::string const &ref);
};
