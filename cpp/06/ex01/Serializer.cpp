#include "Serializer.hpp"
#include "Data.hpp"

bool Serializer::good = true;

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer &ref) { static_cast<void>(ref); }

Serializer& Serializer::operator=(const Serializer &ref)
{ 
	static_cast<void>(ref); 
	return (*this);
}

void	Serializer::setStatic(bool _false)
{
	Serializer::good = _false;
}

bool Serializer::getStatic()
{
	return (Serializer::good);
}

Data*	Serializer::deserialize(uintptr_t ptr)
{
	return reinterpret_cast<Data*>(ptr);
}

uintptr_t	Serializer::serialize(Data *ptr)
{	
	return reinterpret_cast<uintptr_t>(ptr);
}
