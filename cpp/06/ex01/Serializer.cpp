#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer &ref) { static_cast<void>(ref); }

Serializer& Serializer::operator=(const Serializer &ref)
{ 
	static_cast<void>(ref); 
	return (*this);
}

Data*	Serializer::deserialize(uintptr_t ptr)
{
	return reinterpret_cast<Data*>(ptr);
}

uintptr_t	Serializer::serialize(Data *ptr)
{	
	return reinterpret_cast<uintptr_t>(ptr);
}
