#include "FragTrap.hpp"

FragTrap::FragTrap(std::string fragname) : ClapTrap(fragname)
{
	this->name = fragname;
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout << BOLDWHITE << "I am " << BOLDYELLOW << this->name << \
	BOLDWHITE << ", and I wanna give a HIVE-FIVE someone!!!" << std::endl << std::endl;
}

FragTrap::FragTrap() : ClapTrap()
{
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout << BOLDWHITE << "I am " << BOLDYELLOW << this->name << \
	BOLDWHITE << ", and I wanna give a HIVE-FIVE someone!!!" << std::endl << std::endl;
}

FragTrap::FragTrap(const FragTrap &ref)
{
	std::cout << BOLDYELLOW << ref.getName() << BOLDWHITE << " : " << "NOW, I'm coping myself!!!" << std::endl;
	*this = ref;
}

FragTrap&	FragTrap::operator=(const FragTrap &ref)
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

FragTrap::~FragTrap()
{
	std::cout << BOLDYELLOW << this->name << BOLDWHITE << " : I, " << \
	BOLDYELLOW << "the HIVE-FIVE KING" << BOLDWHITE << ", am leaving now..." << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (getEnergyPoints() <= 0)
	{
		std::cout << BOLDYELLOW << this->name << BOLDWHITE << " : " << "I need Energy to move, FOOL!!" << std::endl;
		return ;
	}
	std::cout << BOLDYELLOW << this->name << BOLDWHITE << " attacks " << BOLDRED << target \
	<< BOLDWHITE << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
	if (getAttackDamage() == 0)
	{
		std::cout << BOLDYELLOW << this->name << BOLDWHITE << " : " << "Oh, I missed it..." << std::endl;
	}
	else
		std::cout << BOLDGREEN << "FRAG!!!" << std::endl;
	setEnergyPoints();
	std::cout << std::endl;
}

void	FragTrap::highFivesGuy()
{
	std::string tmp;
	std::string	input;

	while (1)
	{
		std::cout << BOLDWHITE << "---------------------------------------------------" << std::endl;
		std::cout << BOLDYELLOW << this->name << BOLDWHITE << " : " << "Hey, Give me a HIGH FIVE!, " << \
		BOLDGREEN << "\"HIGH FIVE!\"" << BOLDWHITE << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;
		std::getline(std::cin >> std::ws, tmp);
		if (std::cin.eof())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << BOLDRED << "Oh, sorry to hear that..." << std::endl;
			exit(0);
		}
		input = ridrspace(tmp);
		if (input == "HIGH FIVE!")
		{
			std::cout << BOLDYELLOW << this->name << BOLDWHITE << " : " << \
			BOLDBLUE << "Oh yeah!!!" << std::endl;
			std::cout << std::endl;
			break ;
		}
		else
		{
			std::cout << BOLDYELLOW << this->name << BOLDWHITE << " : " << \
			BOLDRED << "Hey, that's not an HIGH FIVE!" << std::endl;
			std::cout << std::endl;	
		}
	}
}
