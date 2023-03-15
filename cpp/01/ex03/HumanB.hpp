#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon club;
		std::string name;
	public:
		HumanB();
		HumanB(std::string name);
		~HumanB();
		void attack();
};

#endif
