#ifndef	WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>
#include "Color.hpp"

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
