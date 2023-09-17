#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "ATarget.hpp"

class TargetGenerator
{
	private:
		TargetGenerator(const TargetGenerator& ref);
		TargetGenerator& operator=(const TargetGenerator& ref);
		std::vector<ATarget*> targets;
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget* target);
		void forgetTargetType(std::string const&);
		ATarget* createTarget(std::string const&);	
};
