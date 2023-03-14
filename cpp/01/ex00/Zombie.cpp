#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
    std::cout << BOLDGREEN << this->name << BOLDRED << " is dead" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << BOLDGREEN << this->name << BOLDRED << " : BraiiiiiiinnnzzzZ... " << std::endl;
}
