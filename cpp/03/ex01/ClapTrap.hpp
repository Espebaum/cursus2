#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#define RESET   	"\033[0m"				/* Reset Color */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */

#include <iostream>
#include <string>
#include <cstdlib>

class ClapTrap
{
	protected:
		std::string		name;
		unsigned int	HitPoints; // represent the health of Clap-Trap
		unsigned int	EnergyPoints;
		unsigned int	AttackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &ref);
		ClapTrap &operator=(const ClapTrap &ref);
		virtual ~ClapTrap();

		// getter-setter
		std::string	getName() const;
		int		getHitPoints() const;
		void	setHitPointsPlus(int point);
		void	setHitPointsMinus(int point);
		int		getEnergyPoints() const;
		void	setEnergyPoints();
		int		getAttackDamage() const;
		void	setAttackDamage(int damage);
		void	showAllStatus();
		
		//functions in subjects
		virtual void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

std::string	ridrspace(std::string input);

#include "ScavTrap.hpp"

#endif
