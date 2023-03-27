#ifndef ClapTrap_HPP
# define ClapTrap_HPP

#define RESET   	"\033[0m"				/* Reset Color */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#include <iostream>
#include <string>
#include <cstdlib>

class ClapTrap
{
	private:
		std::string	name;
		int	HitPoints; // represent the health of Clap-Trap
		int	EnergyPoints;
		int	AttackDamage;
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &ref);
		ClapTrap &operator=(const ClapTrap &ref);
		~ClapTrap();

		// getter-setter starts
		std::string	getName() const;
		void	setAttackDamage(int damage);
		int		getAttackDamage() const;
		int		getHitPoints() const;
		void	setHitPointsMinus(int point);
		void	setHitPointsPlus(int point);
		int		getEnergyPoints() const;
		void	setEnergyPoints();
		void	showName() const;
		// getter-setter ends
		
		//functions in subjects
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
