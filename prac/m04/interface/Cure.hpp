#pragma once

#include <iostream>
#include <string>

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		// Applying OCCF
		Cure();
		Cure(const Cure &ref);
		Cure &operator=(const Cure &ref);
		~Cure();

		// define virtual functions
		AMateria*	clone() const;
		// void	use(ICharacter& target);		
};
