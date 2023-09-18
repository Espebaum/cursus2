#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string name;
		std::string effects;
	public:
		std::string getName() const;
		std::string getEffects() const;
		virtual ASpell* clone() const = 0;
		ASpell(const std::string& name, const std::string& effects);

		ASpell() {}
		virtual ~ASpell() {}
		ASpell(const ASpell& ref) { *this = ref; }
		ASpell& operator=(const ASpell& ref) { static_cast<void>(ref); return *this; }
		void launch(const ATarget& ref) const;
};
