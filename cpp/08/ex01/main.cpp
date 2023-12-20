#include "Span.hpp"

void	withNoIterator()
{
	std::cout << BOLDGREEN << "WITH NO ITERATOR" << RESET << std::endl;
	Span	sp = Span(5);

	sp.addNumber(9); 
	sp.addNumber(3); 
	sp.addNumber(17); 
	sp.addNumber(6); 
	sp.addNumber(11);

	std::cout << BOLDYELLOW << sp.shortestSpan() << std::endl; 
	std::cout << BOLDBLUE << sp.longestSpan() << RESET << std::endl;
	return ;
}

void	withIterator()
{
	std::cout << BOLDGREEN << "WITH ITERATOR" << RESET << std::endl;
	try {
		Span	sp = Span(5);
		std::vector<int> numbers;
		numbers.push_back(11);
		numbers.push_back(30);
		numbers.push_back(12);
		numbers.push_back(23);
		numbers.push_back(9);
		numbers.push_back(90);

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
	std::cout << BOLDGREEN << "NO SPAN" << RESET << std::endl;
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
	std::cout << BOLDGREEN << "LARGE SPAN" << RESET << std::endl;
	try {
		Span	sp = Span(20000);

		for (int i = -10000; i <= 9999; i++)
			sp.addNumber(i);

		std::cout << BOLDYELLOW << sp.shortestSpan() << std::endl;
		std::cout << BOLDBLUE << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << BOLDRED << e.what() << RESET << std::endl;
	}
}

void largeSpanWithIterator(void) 
{
	std::cout << BOLDGREEN << "LARGE SPAN WITH ITERATOR" << RESET << std::endl;
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
	std::cout << std::endl;
	withIterator();
	std::cout << std::endl;
	noSpan();
	std::cout << std::endl;
	largeSpan();
	std::cout << std::endl;
	largeSpanWithIterator();
	return 0;
}
