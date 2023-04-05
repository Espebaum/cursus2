#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class	AMateria;

class Character : public ICharacter
{
	private:
		std::string	name;
		AMateria	*slot[4];
	public:
		// Applying OCCF
		Character();
		Character(std::string name_);
		Character(const Character &ref);
		Character &operator=(const Character &ref);
		
		// define virtual functions
		std::string const& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		~Character();
};

#endif
