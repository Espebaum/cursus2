#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include <string>

#include "AMateria.hpp"
class	ICharacter;

class Ice : public AMateria
{
	public:
		// Applying OCCF
		Ice();
		Ice(const Ice &ref);
		Ice &operator=(const Ice &ref);
		~Ice();

		// define virtual functions
		AMateria* clone() const;
		void use(ICharacter& target);		
};

#endif
