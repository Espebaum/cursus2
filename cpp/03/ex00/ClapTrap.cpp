#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << BOLDWHITE << "-------------------------------------------------------------" << std::endl;
	std::cout << BOLDBLUE << "      CLAP-TRAP appears far away from the Wilderness..." << std::endl;
	std::cout << BOLDWHITE << "-------------------------------------------------------------" << std::endl;
	this->name = name;
	this->HitPoints = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;
	std::cout << BOLDYELLOW << this->name << " : " << BOLDRED << "LET'S TEAR THIS PLANET A NEW ***HOLE! YAAAAAAGHHHHH" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ref)
{
	*this = ref;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &ref)
{
	if (this != &ref)
	{
		this->name = ref.getName();
	}
	return (*this);
}

//---------------- Getter & Setter functions start -----------------//

std::string	ClapTrap::getName() const
{
	return (this->name);
}

void	ClapTrap::showName() const
{
	std::cout << this->getName() << std::endl;
}

int	ClapTrap::getAttackDamage() const
{
	return (this->AttackDamage);
}

void	ClapTrap::setAttackDamage(int damage)
{
	this->AttackDamage = damage;
}	

int	ClapTrap::getHitPoints() const
{
	return (this->HitPoints);
}

void	ClapTrap::setHitPointsMinus(int point)
{
	int	temp = this->HitPoints;
	this->HitPoints = temp - point;

}

void	ClapTrap::setHitPointsPlus(int point)
{
	int	temp = this->HitPoints;
	this->HitPoints = temp + point;
}

int	ClapTrap::getEnergyPoints() const
{
	return (this->EnergyPoints);
}

void	ClapTrap::setEnergyPoints()
{
	this->EnergyPoints--;
}

void	ClapTrap::showAllStatus()
{
	std::cout << std::endl;
	std::cout << BOLDYELLOW << this->name << "\'s" << BOLDBLUE << " STATUS" << std::endl;
	std::cout << BOLDWHITE << "My name is " << BOLDYELLOW << this->getName() << BOLDWHITE << "!!!" << std::endl;
	std::cout << BOLDYELLOW << this->name << "\'s" << BOLDWHITE << " HP : "<< getHitPoints() << std::endl;
	std::cout << BOLDYELLOW << this->name << "\'s" << BOLDWHITE << " Energy points : "<< getEnergyPoints() << std::endl;
	std::cout << BOLDYELLOW << this->name << "\'s" << BOLDWHITE << " Attack damage : "<< getAttackDamage() << std::endl;

}

//---------------- Getter & Setter functions end -------------------//


//---------------- Functions in Subject ----------------------------//
void	ClapTrap::attack(const std::string& target)
{
	if (getEnergyPoints() <= 0)
	{
		std::cout << BOLDYELLOW << this->name << BOLDWHITE << " : " << "I need Energy to move, FOOL!!" << std::endl;
		return ;
	}
	setAttackDamage(rand() % 10);
	std::cout << BOLDYELLOW << this->name << BOLDWHITE << " attacks " << BOLDRED << target \
	<< BOLDWHITE << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
	if (getAttackDamage() == 0)
	{
		std::cout << BOLDYELLOW << this->name << BOLDWHITE << " : " << "Oh, I missed it..." << std::endl;
	}
	setEnergyPoints();
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (getEnergyPoints() <= 0)
	{
		std::cout << BOLDYELLOW << this->name << BOLDWHITE << " : " << "I need Energy to move, FOOL!!" << std::endl;
		return ;
	}
	std::cout << BOLDCYAN << "Someone attacked " << BOLDYELLOW << this->name << BOLDCYAN \
	", so it losts " << BOLDGREEN << amount << BOLDCYAN << " Hit points..." << std::endl;
	this->setHitPointsMinus(amount);
	std::cout << BOLDYELLOW << this->name << " : " << BOLDRED << "OUCH!!! THAT HURTS!!!" << RESET << std::endl;
	setEnergyPoints();
}

void	ClapTrap::beRepaired(unsigned int amount)
{	
	if (getEnergyPoints() <= 0)
	{
		std::cout << BOLDYELLOW << this->name << BOLDWHITE << " : " << "I need Energy to move, FOOL!!" << std::endl;
		return ;
	}
	if (this->HitPoints >= 10)
	{
		std::cout << BOLDYELLOW << this->name << BOLDWHITE << " : " << "Hey, I'm full of HP!!" << std::endl;
		this->HitPoints = 10;
		return ;
	}
	this->setHitPointsPlus(amount);
	if (this->HitPoints >= 10)
	{
		amount = 3 - (this->getHitPoints() - 10);
		this->HitPoints = 10;
	}
	std::cout << BOLDYELLOW << this->name << BOLDCYAN << " repaired " << BOLDYELLOW << "itself" << BOLDCYAN \
	", so it gains " << BOLDGREEN << amount << BOLDCYAN << " Hit points..." << std::endl;
	std::cout << BOLDYELLOW << this->name << " : " << BOLDBLUE << "OK, it's fine" << RESET << std::endl;
	setEnergyPoints();
}

ClapTrap::~ClapTrap()
{
	std::cout << BOLDYELLOW << this->name << " : " << BOLDRED << "I'm just gonna go ahead and cloak now. You can't hear me crying if I cloak!" << std::endl;
	std::cout << BOLDWHITE << "-------------------------------------------------------------" << std::endl;
	std::cout << BOLDBLUE << "              Clap-Trap disappears and cries..." << std::endl;
	std::cout << BOLDWHITE << "-------------------------------------------------------------" << std::endl;
	std::cout << BOLDYELLOW << this->name << " : " << BOLDRED << "so lonely... (sobbing)" << std::endl;
}

// Add the following public member functions so the ClapTrap looks more realistic:

// When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
// When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
// cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points
// or energy points left.
