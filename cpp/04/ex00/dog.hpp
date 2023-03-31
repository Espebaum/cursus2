#ifndef DOG_HPP
# define DOG_HPP

#include "animal.hpp"

class dog : public animal
{
	public:
		dog();
		dog(const dog &ref);
		dog &operator=(const dog &ref);
		~dog();
};

#endif
