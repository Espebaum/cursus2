#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*alive = new Zombie(name);
	return (alive);
}
