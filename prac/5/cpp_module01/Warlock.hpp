#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
	private:
		std::string name;
		std::string title;
		std::vector<ASpell*> Spells;
		Warlock() {};
		Warlock(const Warlock& ref) { *this = ref; }
		Warlock& operator=(const Warlock& ref) { static_cast<void>(ref); return *this; }
	public:
		~Warlock();
		Warlock(const std::string& _name, const std::string& _title);
		const std::string& getName() const;
		const std::string& getTitle() const;
		void setTitle(const std::string& ref);
		void introduce() const;

		void learnSpell(ASpell* Spell);
		void forgetSpell(std::string SpellName);
		void launchSpell(std::string SpellName, const ATarget& ref);
};
