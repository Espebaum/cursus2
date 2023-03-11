#include "phonebook.hpp"

void	Contact::newContact()
{	
	std::string input[5] = {"First Name : ", "Last Name : ", "Nickname : ", "Phone Number : ", "Darkest Secret : "};
	for(int i = 0; i < 5; i++)
	{
		info[i] = "";
		std::cout << input[i];
		while (info[i] == "")
		{
			std::getline(std::cin, info[i]);
			if (std::cin.eof())
			{
				exit(1);
			}
		}
	}
}

void    Contact::showAllcontact()
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
