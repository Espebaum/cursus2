#ifndef CAT_HPP
# define CAT_HPP

#include "animal.hpp"

class cat : public animal
{
	public:
		cat();
		cat(const cat &ref);
		cat &operator=(const cat &ref);
		~cat();
};

#endif
