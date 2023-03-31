#ifndef	ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class animal
{
	protected:
		std::string	type;
	public:
		animal();
		animal(const animal &ref);
		animal &operator=(const animal &ref);
		virtual ~animal();
		virtual void	makeSound() = 0;
};

#include "dog.hpp"

#endif
