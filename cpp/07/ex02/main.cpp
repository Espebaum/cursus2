#include "Array.hpp"

// void    leakcheck()
// {
// 	std::cout<<RESET<<std::endl;
// 	system("leaks Array");
// }

int main(void)
{
	// atexit(leakcheck);
	Array<int> tZero;
	Array<int> tThree1(3);
	Array<int> tThree2(tThree1);
	Array<int> tThree3;
	tThree3 = tThree2;

	std::cout<<tZero.size()<<std::endl;
	std::cout<<tThree1.size()<<std::endl;
	std::cout<<tThree2.size()<<std::endl;
	std::cout<<tThree3.size()<<std::endl;

	try 
	{
		std::cout<<tThree1[0]<<std::endl;
		std::cout<<tThree1[1]<<std::endl;
		std::cout<<tThree1[4]<<std::endl;
	}
	catch (std::exception &e)
	{
		std::cout<<BOLDRED<<e.what()<<std::endl;
	}

	return (0);
}
