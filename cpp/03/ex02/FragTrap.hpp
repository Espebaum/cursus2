#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string fragname);
		FragTrap(const FragTrap &ref);
		FragTrap &operator=(const FragTrap &ref);
		~FragTrap();
		void	attack(const std::string& target);
		void	highFivesGuy();
};

#endif
