#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "Default";
	this->HitPoints = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;
	std::cout << BOLDWHITE << this->name << " : " << "It's not good to have name \"DEFAULT\"..." << std::endl;
}

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
	std::cout << BOLDYELLOW << ref.getName() << BOLDWHITE << " : " << "NOW, I'm coping myself!!!" << std::endl;
	*this = ref;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &ref)
{
	std::cout << BOLDGREEN << "Assigning Operation Started" << std::endl;
	if (this != &ref)
	{
		this->name = ref.getName();
		this->HitPoints = ref.HitPoints;
		this->EnergyPoints = ref.EnergyPoints;
		this->AttackDamage = ref.AttackDamage;
	}
	return (*this);
}

//---------------- Getter & Setter functions start -----------------//
std::string	ClapTrap::getName() const
{
	return (this->name);
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
	if (getHitPoints() <= 0)
	{
		std::cout << BOLDYELLOW << this->name << \
		BOLDWHITE << " : " << BOLDRED << "Oh, I'm out of HP..." << std::endl;
		return ;
	}
	std::cout << BOLDYELLOW << this->name << " : " << BOLDRED << "OUCH!!! THAT HURTS!!!" << RESET << std::endl;
	setEnergyPoints();
	std::cout << std::endl;
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

std::string	ridrspace(std::string input)
{
	for(int i = 0; i < static_cast<int>(input.length()); i++)
	{
		if (std::isspace(input[i]) && i > static_cast<int>(input.length()))
			return (input.substr(0, i));
	}
	return (input);
}
