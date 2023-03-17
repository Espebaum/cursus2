#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void	Harl::debug()
{
	std::cout << BOLDGREEN << "[ DEBUG ]" << std::endl << "Harl : I love having extra bacon " << \
	"for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << RESET << std::endl << std::endl;
}

void	Harl::info()
{
	std::cout << BOLDWHITE << "[ INFO ]" << std::endl << \
	"Harl : I cannot believe adding extra bacon costs more money." << std::endl << "You didn’t put " << \
	"enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET << std::endl << std::endl;
}

void	Harl::warning()
{
	std::cout << BOLDYELLOW << "[ WARNING ]" << std::endl << \
	"Harl : I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming for " << \
	"years whereas you started working here since last month." << RESET << std::endl << std::endl;
}

void	Harl::error()
{
	std::cout << BOLDRED << "[ ERROR ]" << std::endl << "Harl : This is unacceptable! I want to speak to the manager now." << \
	RESET << std::endl << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levels[5] = {"", "DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*f[4])(void) = {
		&Harl::debug, 
		&Harl::info, 
		&Harl::warning,
		&Harl::error
	};

	int	com[5] = {0, };
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (levels[i] == level)
			com[i] = i;
		sum += com[i];
	}
	
	switch (sum)
	{
		case 1:
			(this->*f[0])();
			break;
		case 2:
			(this->*f[1])();
			break;
		case 3:
			(this->*f[2])();
			break;
		case 4:
			(this->*f[3])();
			break;
		default:
			std::cout << BOLDBLUE << "Harl is complaining heavily..." << std::endl;
			break;
	}
}
