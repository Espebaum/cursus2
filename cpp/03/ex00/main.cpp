#include "ClapTrap.hpp"

std::string	ridrspace(std::string input)
{
	for(int i = 0; i < static_cast<int>(input.length()); i++)
	{
		if (std::isspace(input[i]))
			return (input.substr(0, i));
	}
	return (input);
}


int	main()
{
	std::string	input;
	const std::string	target = "DUMMY";
	ClapTrap	Clap("CL4P-TP");

	while (1)
	{
		std::cout << std::endl;
		std::cout << BOLDWHITE << "---------------------------------------------------------------------------" << std::endl;
		std::cout << BOLDBLUE << "SO, WHAT YOU GONNA DO?, (choose one of STATUS, ATTACK, REPAIR, ANNOY, EXIT)" << std::endl;
		std::cout << BOLDWHITE << "---------------------------------------------------------------------------" << std::endl;
		std::getline(std::cin >> std::ws, input);
		if (std::cin.eof())
		{
			std::cout << BOLDYELLOW << Clap.getName() << BOLDWHITE << " : " << BOLDRED << "so, you pushed the SELF-DESTURCTION BUTTON, Huh?," \
			<< " then I'm gonna DESTROY this PROGRAM!!!" << std::endl;
			exit (0);
		}
		input = ridrspace(input);
		if (input == "STATUS")
		{
			Clap.showAllStatus();
		}
		else if (input == "ATTACK")
		{
			Clap.attack(target);
		}
		else if (input == "REPAIR")
		{
			Clap.beRepaired(3);
		}
		else if (input == "ANNOY")
		{
			Clap.takeDamage(rand() % 10);
			if (Clap.getHitPoints() <= 0)
			{
				std::cout << BOLDYELLOW << Clap.getName() << \
				BOLDWHITE << " : " << BOLDRED << "Oh, I'm out of HP..." << std::endl;
				break ;
			}
		}
		else if (input == "EXIT")
		{
			break ;
		}
		else
		{
			std::cout << BOLDYELLOW << Clap.getName() << BOLDWHITE << " : " << BOLDRED << "CHOOSE ONE OF COMMANDS YOU FOOL!!!" << std::endl;
		}
	}
	return (0);
}
