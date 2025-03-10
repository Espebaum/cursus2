#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string scavname);
		ScavTrap(const ScavTrap &ref);
		ScavTrap &operator=(const ScavTrap &ref);
		~ScavTrap();
		void	guardGate();
		void	attack(const std::string& target);
};

#endif
