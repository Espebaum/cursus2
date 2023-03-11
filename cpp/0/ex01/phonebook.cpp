#include "phonebook.hpp"

bool	PhoneBook::checknum(std::string s)
{
	if (s.length() > 1)
		return (1);
	if (s[0] - '0' > index || s[0] - '0' > 8)
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
		std::cout << BOLDBLACK << std::setw(10) << "index" << "|" << std::setw(10) << "first name" << "|" << std::setw(10) << "last name" << "|" << std::setw(10) << "nickname" << std::endl;
		for(int i = 0; i < 8; i++)
		{
			if (i == index)
				break ;
			contacts[i].showContact(i);
		}
		std::string input;
		std::cin >> input;
		if (checknum(input))
		{
			std::cout << BOLDRED << "Error!, Please enter a number in correct range!" << std::endl;
			return ;
		}
		int	num = input[0] - '0';
		if (num == 0)
		{
			std::cout << BOLDRED << "Error!, Please enter a number in correct range!" << std::endl;
			return ;
		}
		contacts[num - 1].showAllcontact();
	}
}

void	PhoneBook::add()
{
	contacts[index % 8].newContact();
	index++;
}