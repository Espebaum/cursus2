#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << BOLDRED << "Invalid Argument!" << std::endl;
		return 0;
	}
	else
	{
		BitcoinExchange		Ex;
		Ex.show(argv[1]);
	}

	return 0;
	//유효성 검사
	//data.csv를 열어
	//쪼개서 맵에 집어넣어
	//input.txt를 열어
	//돌면서 data.csv랑 비교해
	//맞는거 알아서 출력해
}
