#pragma once

#include <iostream>
#include <string>

class ATarget;

class ASpell
{
	protected:
		std::string name;
		std::string effects;

	public:
		ASpell();
		ASpell(const ASpell& ref);
		ASpell& operator=(const ASpell& ref);
		virtual ~ASpell();
		ASpell(std::string _name, std::string _effects);

		std::string	getName() const;
		std::string getEffects() const;
		virtual ASpell* clone() const = 0;
		void launch(const ATarget& ref);
};
