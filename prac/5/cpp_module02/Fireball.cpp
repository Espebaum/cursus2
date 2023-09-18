#include "Fireball.hpp"

Fireball::Fireball()
{
	this->name = "Fireball";
	this->effects = "burnt to a crisp";
}

Fireball* Fireball::clone() const
{
	Fireball* fire = new Fireball();
	return fire;
}
