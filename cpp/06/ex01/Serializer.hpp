#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>

struct Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& ref);
		Serializer& operator=(const Serializer& ref);
		~Serializer();

	public:
		static Data*		deserialize(uintptr_t ptr);
		static uintptr_t	serialize(Data *ptr);
};

#endif
