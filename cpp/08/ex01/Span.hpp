#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <exception>

#define RESET		"\033[0m"
#define BOLDBLACK	"\033[1m\033[30m"
#define BOLDRED		"\033[1m\033[31m"
#define BOLDGREEN	"\033[1m\033[32m"
#define BOLDYELLOW	"\033[1m\033[33m"
#define BOLDBLUE	"\033[1m\033[34m"
#define BOLDMAGENTA	"\033[1m\033[35m"
#define BOLDCYAN	"\033[1m\033[36m"
#define BOLDWHITE	"\033[1m\033[37m"

class Span
{
	private:
		std::vector<int>	array;
		int	len;
		Span();

	public:
		Span(unsigned int N);
		~Span();
		Span(const Span& ref);
		Span& operator=(const Span& ref);

		std::vector<int>::iterator	getBegin();
		std::vector<int>::iterator	getEnd();
		int	getLen() const;
		int	getSize() const;

		void	addNumber(int N);
		int		longestSpan();
		int		shortestSpan();
		
		template <typename T>
		void addRange(T first, T last) {
			while (first != last) {
				addNumber(*first);
				++first;
			}
		}

		class VectorSizeError : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
