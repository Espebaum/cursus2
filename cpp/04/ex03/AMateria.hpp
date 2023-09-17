#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>

class	ICharacter;
class AMateria
{
	protected:
		std::string	type_;
	public:
		// Applying OCCF
		AMateria();
		AMateria(std::string const & type);
		// [...]
		std::string const &	getType() const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
		virtual void	use(ICharacter& target);

		//define my function
		void	setType(std::string	content);
		virtual	~AMateria();
};

#endif
