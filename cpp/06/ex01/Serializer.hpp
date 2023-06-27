#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>

struct Data;

class Serializer
{
	private:
		static bool		good;
	
	public:
		Serializer();
		Serializer(const Serializer& ref);
		~Serializer();
		Serializer& operator=(const Serializer& ref);

		static bool getStatic();
		static void	setStatic(bool b);

		Data*		deserialize(uintptr_t ptr);
		uintptr_t	serialize(Data *ptr);
};

#endif
