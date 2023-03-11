#include "PhoneBook.hpp"

bool	checkTab(std::string s)
{
	for(int i = 0; i < static_cast<int>(s.length()); i++)
	{
		if (s[i] == '\t')
			return (1);
	}
	return (0);
}

bool	Contact::newContact()
{	
	std::string input[5] = {"First Name : ", "Last Name : ", "Nickname : ", "Phone Number : ", "Darkest Secret : "};
	std::string	tmp;

	for(int i = 0; i < 5; i++)
	{
		info[i] = "";
		std::cout << input[i];
		while (info[i] == "")
		{
			std::getline(std::cin >> std::ws, tmp);
			if (checkTab(tmp))
			{
				std::cout << BOLDRED << "Error!, Do not enter TAB after the word!" << std::endl;
				return (0);
			}
			else
				info[i] = tmp;
			if (std::cin.eof())
			{
				exit(1);
			}
		}
	}
	return (1);
}

void    Contact::showAllContact()
{
	std::string input[5] = {"First Name : ", "Last Name : ", "Nickname : ", "Phone Number : ", "Darkest Secret : "};

	for (int i = 0; i < 5; i++)
	{
		std::cout << BOLDCYAN << input[i] << BOLDMAGENTA << info[i] << std::endl;
	}
}

std::string Contact::checkContact(std::string s)
{
	if (s.length() <= 10)
		return (s);
	else
		return (s.substr(0, 9) + ".");
}

void	Contact::showContact(int i)
{
	std::string	check;

	std::cout << std::setw(10) << i + 1 << "|";
	std::cout << std::setw(10) << checkContact(info[0]) << "|";
	std::cout << std::setw(10) << checkContact(info[1]) << "|";
	std::cout << std::setw(10) << checkContact(info[2]) << std::endl;
}
