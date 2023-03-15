#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string s)
{
	Zombie	*Hordes = new Zombie[N];

	for(int i = 0; i < N; i++)
	{
		Hordes[i].setName(s);
		Hordes[i].announce();
	}
	return Hordes;
}
