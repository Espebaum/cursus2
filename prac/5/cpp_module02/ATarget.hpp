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
		const std::string& getType() const;
		virtual ATarget* clone() const = 0;
		ATarget(const std::string& type);
		
		ATarget() {}
		virtual ~ATarget() {}
		ATarget(const ATarget& ref) { *this = ref; }
		ATarget& operator=(const ATarget& ref) { static_cast<void>(ref); return *this; }
		void getHitBySpell(const ASpell& ref) const;
};
