#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
}

bool	PhoneBook::checknum(std::string s)
{
	if (s.length() > 1)
		return (1);
	if (s[0] - '0' < 1 || s[0] - '0' > index || s[0] - '0' > 8)
		return (1);
	return (0);
}

void	PhoneBook::search()
{
	if (index == 0)
	{
		std::cout << BOLDRED << "There's no contact entered in Phonebook!" << std::endl;
		return ;
	}
	else
	{
		// std::cout.setf(std::ios::right);
		std::cout << BOLDBLACK << std::setw(10) << "index" << "|" << std::setw(10) \
		<< "first name" << "|" << std::setw(10) << "last name" << "|" << std::setw(10) << "nickname" << std::endl;
		for(int i = 0; i < 8; i++)
		{
			if (i == index)
				break ;
			contacts[i].showContact(i);
		}
		std::string input;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << RED << "CTRL D means END OF INPUT!" << std::endl;
			exit(0);
		}
		if (checknum(input))
		{
			std::cout << BOLDRED << "Error!, Please enter a number in correct range!" << std::endl;
			return ;
		}
		int	num = input[0] - '0';
		contacts[num - 1].showAllContact();
	}
}

void	PhoneBook::add()
{
	contacts[index % 8].newContact();
	index++;
}
