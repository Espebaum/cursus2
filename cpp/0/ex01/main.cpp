#include "phonebook.hpp"

int main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	while (1)
	{
		std::cout << BOLDBLUE << "Input Command(ADD, SEARCH, EXIT)" << "\033[0m" << std::endl;
		std::cin >> input;
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