#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock(const std::string& _name, const std::string& _title) : \
		name(_name), title(_title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
}

Warlock::Warlock(const Warlock& ref)
{
	static_cast<void>(ref);
}

Warlock& Warlock::operator=(const Warlock& ref)
{
	static_cast<void>(ref);
	return *this;
}

void	Warlock::setTitle(const std::string& _title)
{
	this->title = _title;
}

void	Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

const std::string& Warlock::getName() const
{
	return name;
}

const std::string& Warlock::getTitle() const
{
	return title;
}
