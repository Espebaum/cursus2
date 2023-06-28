#include "Array.hpp"

// void    leakcheck()
// {
// 	std::cout<<RESET<<std::endl;
// 	system("leaks Array");
// }

int main(void)
{
	// atexit(leakcheck);
	{
		Array<int> iZero;
		Array<int> iThree1(3);
		Array<int> iThree2(iThree1);
		Array<int> iThree3;
		iThree3 = iThree2;

		std::cout<<iZero.size()<<' ';
		std::cout<<iThree1.size()<<' ';
		std::cout<<iThree2.size()<<' ';
		std::cout<<iThree3.size()<<std::endl;

		iThree1[0] = 4;
		iThree1[1] = 2;
		iThree1[2] = 1;

		try 
		{
			std::cout<<iThree1[0]<<' ';
			std::cout<<iThree1[1]<<std::endl;
			std::cout<<iThree2[0]<<' ';
			std::cout<<iThree2[1]<<std::endl;
			std::cout<<iThree1[4]<<std::endl;
		}
		catch (std::exception &e)
		{
			std::cout<<BOLDRED<<e.what()<<std::endl;
		}
	}
		std::cout<<BOLDYELLOW<<"-----------------------------------------"<<RESET<<std::endl;
	{
		Array<std::string> sZero;
		Array<std::string> sThree1(3);

	}
	return (0);
}
