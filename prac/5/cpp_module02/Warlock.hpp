#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "ATarget.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"

class Warlock 
{
	private:
		const std::string	name; // 체크
		std::string title;
		SpellBook	Spells;
		Warlock();
		Warlock(const Warlock& ref);
		Warlock& operator=(const Warlock& ref);
	
	public:
		~Warlock();
		Warlock(const std::string& _name, const std::string& _title); 
		const std::string& getName() const;
		const std::string& getTitle() const;
		void setTitle(const std::string& title);
		void introduce() const;

		void learnSpell(ASpell* spell);
		void forgetSpell(std::string SpellName);
		void launchSpell(std::string SpellName, const ATarget& target);
};
