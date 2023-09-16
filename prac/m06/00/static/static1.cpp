#include "Global.hpp"
#include "static1.hpp"

namespace File1
{
	void	SetVariables(int i)
	{
		s_val = i;
		g_val = i;
		std::cout << BOLDBLUE << "G_val = " << g_val << ", S_val = " \
		<< s_val << " in File1::SetVariable" << RESET << std::endl;
	}
	void IncrementValues()
	{
		s_val++;
		g_val++;
		std::cout << BOLDGREEN << "G_val = " << g_val << ", S_val= " \
		<< s_val << " in File1::IncrementValues" << RESET << std::endl;
	}

}
