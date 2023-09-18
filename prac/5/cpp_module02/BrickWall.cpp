#include "BrickWall.hpp"

BrickWall::BrickWall()
{
	this->type = "Inconspicuous Red-brick Wall";
}

BrickWall* BrickWall::clone() const
{
	BrickWall* dum = new BrickWall();
	return dum;
}
