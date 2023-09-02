#include "Span.hpp"

void	withNoIterator()
{
	Span	sp = Span(5);

	sp.addNumber(6); 
	sp.addNumber(3); 
	sp.addNumber(17); 
	sp.addNumber(9); 
	sp.addNumber(11);

	std::cout << BOLDYELLOW << sp.shortestSpan() << std::endl; 
	std::cout << BOLDBLUE << sp.longestSpan() << RESET << std::endl;
	return ;
}

void	withIterator()
{
	try {
		Span	sp = Span(5);
		std::vector<int> numbers;
		numbers.push_back(1);
		numbers.push_back(3);
		numbers.push_back(5);
		numbers.push_back(10);
		numbers.push_back(11);
		numbers.push_back(20);

		sp.addRange(numbers.begin(), numbers.end());
		std::cout << BOLDYELLOW << sp.shortestSpan() << std::endl; 
		std::cout << BOLDBLUE << sp.longestSpan() << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << BOLDRED << e.what() << RESET << std::endl;
	}
	return ;
}

void	noSpan()
{
	{
		try {
			Span	sp = Span(0);
			sp.addNumber(8);
			std::cout << BOLDYELLOW << sp.shortestSpan() << std::endl; 
			std::cout << BOLDBLUE << sp.longestSpan() << RESET << std::endl;
		} catch (std::exception &e) {
			std::cout << BOLDRED << e.what() << RESET << std::endl;
		}
	}

	{
		try {
			Span	sp = Span(1);
			sp.addNumber(8);
			std::cout << BOLDYELLOW << sp.shortestSpan() << std::endl; 
			std::cout << BOLDBLUE << sp.longestSpan() << RESET << std::endl;
		} catch (std::exception &e) {
			std::cout << BOLDRED << e.what() << RESET << std::endl;
		}
	}
}

void largeSpan(void) 
{
	Span	sp = Span(20000);

	for (int i = -10000; i <= 9999; i++)
		sp.addNumber(i);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void largeSpanWithIterator(void) 
{
	try {
		Span	sp = Span(20000);
		std::vector<int> numbers;
		for (int i = -10000; i <= 10000; i++)
			numbers.push_back(i);
		sp.addRange(numbers.begin(), numbers.end());

		std::cout << BOLDYELLOW << sp.shortestSpan() << std::endl; 
		std::cout << BOLDBLUE << sp.longestSpan() << RESET << std::endl;

	} catch (std::exception &e) {
		std::cout << BOLDRED << e.what() << RESET << std::endl;
	}
}

int main(void)
{
	withNoIterator();
	withIterator();
	noSpan();
	largeSpan();
	largeSpanWithIterator();

	return 0;
}
