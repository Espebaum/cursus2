#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
	PhoneBook	phonebook;
	std::string	input;
	std::string tmp;

	while (1)
	{
		std::cout << BOLDYELLOW << "===========================================" << std::endl;
		std::cout << BOLDBLUE << "     Input Command (ADD, SEARCH, EXIT)" << std::endl;
		std::cout << BOLDYELLOW << "===========================================" << BOLDWHITE << std::endl;
		std::getline(std::cin >> std::ws, tmp);
		if (std::cin.eof())
		{
			std::cout << RED << "CTRL D means END OF INPUT!" << std::endl;
			exit(0);
		}
		input = ridrspace(tmp);
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
			std::cout << BOLDRED << "Error! Enter command one of three!" << std::endl;
	}
	return (0);
}
