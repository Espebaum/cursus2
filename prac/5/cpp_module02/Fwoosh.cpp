#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
{
	this->name = "Fwoosh";
	this->effects = "fwooshed";
}

Fwoosh::~Fwoosh() {}

Fwoosh* Fwoosh::clone() const
{
	Fwoosh *foo = new Fwoosh();
	return foo;
}
