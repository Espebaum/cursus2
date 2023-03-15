#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*heap = new Zombie(name);
	return (heap);
}
