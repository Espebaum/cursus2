#pragma once

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <sstream>
# include <cmath>
# include <sys/time.h>

#define RESET		"\033[0m"
#define BOLDBLACK	"\033[1m\033[30m"
#define BOLDRED		"\033[1m\033[31m"
#define BOLDGREEN	"\033[1m\033[32m"
#define BOLDYELLOW	"\033[1m\033[33m"
#define BOLDPURPLE	"\033[1m\033[34m"
#define BOLDMAGENTA	"\033[1m\033[35m"
#define BOLDBLUE	"\033[1m\033[36m"
#define BOLDWHITE	"\033[1m\033[37m"

struct Pair 
{
    double mainChain;
    double pendElement;
};

class PmergeMe
{
	private:
		std::string				input;
		std::vector<int>		vecJacobsthal;
		std::deque<int>			deqJacobsthal;

		std::vector<double>		vec;
		std::vector<double>		vecMainChain;
		std::vector<double>		vecPendElement;

		std::deque<double>		deq;
		std::deque<double>		deqMainChain;
		std::deque<double>		deqPendElement;

	public:
		// Function //
		void    parse(char **argv);
		void	fillJacobsthal();

		// Vector //
		void	vecSort();
		void	reorderVec();
		void	makePairs(std::vector<Pair> &pairs);
		void	devidePairs(std::vector<Pair> &pairs);
		void	mergeInsertVec();
		void	insertVecElement(int idx);
		void	showVec();

		// Deque //
		void	deqSort();
		void	reorderDeq();
		void	makePairs(std::deque<Pair> &pairs);
		void	devidePairs(std::deque<Pair> &pairs);
		void	mergeInsertDeq();
		void	insertDeqElement(int idx);

		// OCCF // 
		PmergeMe();
		PmergeMe(const PmergeMe& ref);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& ref);

		// exception //
		class ValueError : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

bool operator<(const Pair& left, const Pair& right);
