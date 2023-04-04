#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>
#include <sstream>
// #include "Animal.hpp"

#include "Color.hpp"
class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain();
		Brain(const Brain &ref);
		Brain &operator=(const Brain &ref);
		~Brain();
		std::string	getIdea(int i) const;
		void	setIdea(int i, std::string content);
};

#endif
