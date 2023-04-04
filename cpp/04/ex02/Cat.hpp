#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"
#include "Color.hpp"

class Cat : public Animal
{
	private:
		Brain	*head;
	public:
		Cat();
		Cat(const Cat &ref);
		Cat &operator=(const Cat &ref);
		~Cat();
		void	makeSound();
		std::string	getType() const;
		std::string	getThink(int i) const;
		void	setThink(int i, std::string	content);
};

#endif
