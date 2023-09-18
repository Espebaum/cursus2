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
		std::string	getName() const;
		std::string getEffects() const;
		virtual ASpell* clone() const = 0;
		
		ASpell() {}
		ASpell(const ASpell& ref) { *this = ref; }
		ASpell& operator=(const ASpell& ref) { static_cast<void>(ref); return *this; }
		virtual ~ASpell() {}
		ASpell(const std::string& _name, const std::string& _effects);
		void	launch(const ATarget& ref) const;	
};
