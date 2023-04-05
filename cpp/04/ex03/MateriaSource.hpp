#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*power[4];
	public:
		// Applying OCCF
		MateriaSource();
		MateriaSource(const MateriaSource &ref);
		MateriaSource &operator=(const MateriaSource &ref);
		~MateriaSource();
		
		// define virtual functions
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
