#include "Zombie.hpp"

Zombie::Zombie()
{
    this->name = "Default Zombie";
    std::cout<< BOLDWHITE << "The " << BOLDRED << "DEFAULT ZOMBIE CONSTRUCTOR " \
    << BOLDWHITE << "has been worked" << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout<< BOLDWHITE << "The " << BOLDRED << "ZOMBIE CONSTRUCTOR " \
    << BOLDWHITE << "has been worked" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << BOLDGREEN << this->name << BOLDRED << " is dead" << BOLDWHITE << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << BOLDGREEN << this->name << BOLDRED << " : BraiiiiiiinnnzzzZ... " << std::endl;
}
