#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}

void	TargetGenerator::learnTargetType(ATarget* Target)
{
	if (Target)
		Targets.push_back(Target);
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
	ATarget* MyTarget = NULL;
	for (size_t i = 0; i < Targets.size(); i++)
	{
		if (TargetType == Targets[i]->getType())
			MyTarget = Targets[i];
	}
	return MyTarget;
}


