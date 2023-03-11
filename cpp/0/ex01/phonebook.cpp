#include "phonebook.hpp"

bool	PhoneBook::checknum(std::string s)
{
	if (s.length() > 1)
		return (1);
	if (s[0] - '0' > index || s[0] - '0' > 7)
		return (1);
	return (0);
}

void	PhoneBook::search()
{
	if (index == 0)
	{
		std::cout << "no contact" << std::endl;
		return ;
	}
	else
	{
		std::cout << std::setw(10) << "index" << "|" << std::setw(10) << "first name" << "|" << std::setw(10) << "last name" << "|" << std::setw(10) << "nickname" << std::endl;
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
			std::cout << "out of range or wrong number" << std::endl;
			return ;
		}
		int	num = input[0] - '0';
		contacts[num - 1].showAllcontact();
	}
}

void	PhoneBook::add()
{
	contacts[index % 7].newContact();
	index++;
}