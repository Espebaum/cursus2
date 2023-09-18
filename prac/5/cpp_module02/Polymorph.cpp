#include "Polymorph.hpp"

Polymorph::Polymorph()
{
	this->name = "Polymorph";
	this->effects = "turned into a critter";
}

Polymorph* Polymorph::clone() const
{
	Polymorph* fire = new Polymorph();
	return fire;
}
