#ifndef	WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

#define RESET   	"\033[0m"				/* Reset Color */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &ref);
		WrongAnimal &operator=(const WrongAnimal &ref);
		virtual ~WrongAnimal();
		virtual void	makeSound() const;
		virtual	std::string	getType() const;
};

#include "WrongCat.hpp"

#endif
