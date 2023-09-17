#include "Dummy.hpp"

Dummy::Dummy()
{
	this->type = "Target Practice Dummy";
}

Dummy::~Dummy() {}

Dummy* Dummy::clone() const
{
	Dummy* dum = new Dummy();
	return dum;
}
