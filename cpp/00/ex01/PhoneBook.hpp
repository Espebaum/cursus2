#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		int     index;
		Contact contacts[8];
	public:
		PhoneBook();
		void    add();
		void    search();
		bool	checknum(std::string s);
};

#endif
