#pragma once

#include <iostream>
#include <string>

class ASpell;

class ATarget
{
	protected:
		std::string type;
	public:
		ATarget();
		ATarget(const ATarget& ref);
		ATarget& operator=(const ATarget& ref);
		virtual ~ATarget();
		ATarget(std::string _type);

		const std::string& getType() const;
		virtual ATarget* clone() const = 0;
		void getHitBySpell(const ASpell& ref) const;	
};

