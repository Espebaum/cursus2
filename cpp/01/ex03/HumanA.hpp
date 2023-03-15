#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon param;
		std::string name;
	public:
		HumanA();
		HumanA(std::string name, Weapon weapon);
		~HumanA();
		void attack();
};

#endif
