#include "Span.hpp"

int main(void)
{
    Span sp = Span(5);

    sp.addNumber(6); 
    sp.addNumber(3); 
    sp.addNumber(17); 
    sp.addNumber(9); 
    sp.addNumber(11);
    sp.addNumber(100);
    sp.addNumber(101);

    try{
        std::cout << BOLDYELLOW << sp.shortestSpan() << std::endl; 
        std::cout << BOLDBLUE << sp.longestSpan() << RESET << std::endl;
    } catch (std::exception &e) {
		std::cout<<BOLDRED<<e.what()<<RESET<<std::endl;
	}

    std::vector<int>::iterator   iterB;

    // for (iterB = sp.getBegin(); iterB != sp.getEnd(); iterB++)
    //     std::cout<<*iterB<<' ';
    // std::cout<<std::endl;
    
    return 0;
}
