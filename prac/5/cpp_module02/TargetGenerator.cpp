#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}

TargetGenerator::TargetGenerator(const TargetGenerator& ref)
{
	*this = ref;
}

TargetGenerator& TargetGenerator::operator=(const TargetGenerator& ref)
{
	static_cast<void>(ref);
	return *this;
}

void TargetGenerator::learnTargetType(ATarget* target)
{
	if (target)
		targets.push_back(target);
}

void TargetGenerator::forgetTargetType(std::string const& targetName)
{
	for (size_t i = 0; i < targets.size(); i++)
	{
		if (targetName == targets[i]->getType())
			targets.erase(targets.begin() + i);
	}
}

ATarget* TargetGenerator::createTarget(std::string const& targetName)
{
	ATarget* newTarget = NULL;
	for (size_t i = 0; i < targets.size(); i++)
	{
		if (targetName == targets[i]->getType())
			newTarget = targets[i];
	}
	return newTarget;
}
