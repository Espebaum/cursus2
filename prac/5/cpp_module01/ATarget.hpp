#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string type;
	public:
		std::string	getType() const;
		virtual ATarget* clone() const = 0;
		
		ATarget() {}
		ATarget(const ATarget& ref) { *this = ref; }
		ATarget& operator=(const ATarget& ref) { static_cast<void>(ref); return *this; }
		virtual ~ATarget() {}
		ATarget(const std::string& _type);
		void	getHitBySpell(const ASpell& ref) const;	
};

