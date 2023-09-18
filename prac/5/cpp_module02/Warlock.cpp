#include "Warlock.hpp"

Warlock::Warlock(const std::string& _name, const std::string& _title) :
	name(_name), title(_title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
}

const std::string& Warlock::getName() const
{
	return name;
}

const std::string& Warlock::getTitle() const
{
	return title;
}

void	Warlock::setTitle(const std::string& ref)
{
	this->title = ref;
}

void	Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell* Spell)
{
	Spells.learnSpell(Spell);
}

void	Warlock::forgetSpell(std::string SpellName)
{
	Spells.forgetSpell(SpellName);
}

void	Warlock::launchSpell(std::string SpellName, const ATarget& ref)
{
	if (Spells.createSpell(SpellName))
		Spells.createSpell(SpellName)->launch(ref);
}
