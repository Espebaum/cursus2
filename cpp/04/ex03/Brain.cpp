#include "Brain.hpp"

Brain::Brain()
{
	std::cout << BOLDBLUE << "Dogs and Cats always think about something" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::stringstream tmp;
		tmp << "LOVE " << i;
		this->ideas[i] = tmp.str();
	}
	std::cout << std::endl;
}

Brain::~Brain()
{
	std::cout << "I'm deleting my head lol" << std::endl;
}

Brain::Brain(const Brain &ref)
{
	*this = ref;
}

Brain&	Brain::operator=(const Brain &ref)
{
	if (this != &ref)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = ref.ideas[i];
		}	
	}
	return (*this);
}

std::string Brain::getIdea(int i) const
{
	if (i > 99 || i < 0)
		return "It's so complicated...";
	return ideas[i];
}

void	Brain::setIdea(int i, std::string content)
{
	if (i > 99 || i < 0)
	{
		std::cout << "It's so complicated...\n" << std::endl;
		return ;
	}
	this->ideas[i] = content;
}
