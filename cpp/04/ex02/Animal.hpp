#ifndef	ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

#include "Color.hpp"
#include "Brain.hpp"

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal &ref);
		Animal &operator=(const Animal &ref);
		virtual ~Animal();
		virtual void	makeSound() = 0;
		virtual	std::string	getType() const;
		virtual std::string	getThink(int i) const;
		virtual void	setThink(int i, std::string	content);
};

#endif
