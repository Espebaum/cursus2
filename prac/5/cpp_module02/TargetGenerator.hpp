#pragma once

#include <vector>
#include "ATarget.hpp"

class ATarget;

class TargetGenerator
{
	private:
		std::vector<ATarget*> Targets;
		TargetGenerator(const TargetGenerator& ref) { *this = ref; }
		TargetGenerator& operator=(const TargetGenerator& ref) { static_cast<void>(ref); return *this; }
	public:
		TargetGenerator();
		~TargetGenerator();

		void	learnTargetType(ATarget* target);
		void	forgetTargetType(const std::string& TargetType);
		ATarget*	createTarget(const std::string& TargetType);
};

