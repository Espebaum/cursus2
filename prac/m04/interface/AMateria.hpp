#pragma once

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
        AMateria(const AMateria &ref);
        AMateria& operator=(const AMateria &ref);
		virtual	~AMateria();

		AMateria(std::string const& type);
		std::string const&	getType() const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
		// virtual void	use(ICharacter& target);
};
