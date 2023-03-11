#include "PhoneBook.hpp"

std::string	ridspace(std::string tmp)
{
	for(int i = 0; i < static_cast<int>(tmp.length()); i++)
	{
		if (std::isspace(tmp[i]))
			return (tmp.substr(0, i));
	}
	return (tmp);
}

int main(void)
{
	PhoneBook	phonebook;
	std::string	input;
	std::string tmp;

	while (1)
	{
		std::cout << BOLDYELLOW << "===========================================" << std::endl;
		std::cout << BOLDBLUE << "Input Command(ADD, SEARCH, EXIT)" << std::endl;
		std::cout << BOLDYELLOW << "===========================================" << BOLDWHITE << std::endl;
		std::getline(std::cin >> std::ws, tmp);
		if (std::cin.eof())
		{
			exit(1);
		}
		input = ridspace(tmp);
		if (input == "ADD")
		{
			phonebook.add();
		}
		else if (input == "SEARCH")
		{
			phonebook.search();
		}
		else if (input == "EXIT")
		{
			break ;
		}
		else
			std::cout << BOLDRED << "Wrong Input!" << std::endl;
	}
	return (0);
}
