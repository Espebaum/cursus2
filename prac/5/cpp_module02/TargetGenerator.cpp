#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}

void	TargetGenerator::learnTargetType(ATarget* target)
{
	if (target)
		Targets.push_back(target);
}

void	TargetGenerator::forgetTargetType(const std::string& TargetType)
{
	for (size_t i = 0; i < Targets.size(); i++)
	{
		if (TargetType == Targets[i]->getType())
			Targets.erase(Targets.begin() + i);
	}
}

ATarget*	TargetGenerator::createTarget(const std::string& TargetType)
{
	ATarget* newTarget = NULL;
	for (size_t i = 0; i < Targets.size(); i++)
	{
		if (TargetType == Targets[i]->getType())
			newTarget = Targets[i];
	}
	return newTarget;
}

