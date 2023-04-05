#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"
#include "Color.hpp"

class Dog : public Animal
{	
	private:
		Brain	*head;
	public:
		Dog();
		Dog(const Dog &ref);
		Dog &operator=(const Dog &ref);
		~Dog();
		void	makeSound() const;
		std::string	getType() const;
		std::string	getThink(int i) const;
		void	setThink(int i, std::string	content);
};


#endif
