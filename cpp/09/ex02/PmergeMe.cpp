#include "PmergeMe.hpp"

void	PmergeMe::devidePairs(std::vector<Pair> &pairs)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		vecMainChain.push_back(pairs[i].a);
		vecPendElement.push_back(pairs[i].b); 
	}
	if (vec.size() % 2 != 0)
		vecPendElement.push_back(vec.back());
}

void	PmergeMe::makePairs(std::vector<Pair> &pairs)
{
	int n = vec.size();

    if (n % 2 != 0)
        n -= 1;


    for (int i = 0; i < n; i += 2) {
		Pair	pair;
		pair.a = vec[i];
		pair.b = vec[i + 1];
		pairs.push_back(pair);
    }
	std::sort(pairs.begin(), pairs.end());
}

void	PmergeMe::reorderVec()
{
    int n = vec.size();
    
    if (n % 2 != 0)
        n -= 1;
    
    for (int i = 0; i < n; i += 2) {
        if (vec[i] < vec[i + 1]) {
            std::swap(vec[i], vec[i + 1]);
        }
    }
}

void	PmergeMe::vecSort()
{
	std::vector<Pair> pairs;
	reorderVec();
	makePairs(pairs);
	devidePairs(pairs);

	std::cout << "MAIN CHAIN : ";
	for (size_t i = 0; i < vecMainChain.size(); i++)
		std::cout << vecMainChain[i] << ' ';
	std::cout << std::endl;

	std::cout << "PEND : ";
	for (size_t i = 0; i < vecPendElement.size(); i++)
		std::cout << vecPendElement[i] << ' ';
	std::cout << std::endl;
}

void	PmergeMe::deqSort()
{

}

void    PmergeMe::parse(char **argv)
{
	std::vector<std::string>	tmp;
	int i = 1;

	while (argv[i])
		tmp.push_back(argv[i++]);
	
	try {
		char	*end;
		for (size_t i = 0; i < tmp.size(); i++) {
			double	value = std::strtod(tmp[i].c_str(), &end);
			if (value == 0.0 && !std::isdigit(tmp[i][0]))
				throw ValueError();
			if (*end != '\0' && std::strcmp(end, "f"))
				throw ValueError();
			if (static_cast<int>(value) != value || value < 0)
				throw ValueError();
			vec.push_back(value);
			deq.push_back(value);
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

// DEBUG //

void	PmergeMe::showVec()
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << std::endl;	
}

// EXCEPTION //

const char* PmergeMe::ValueError::what() const throw()
{
	return "Error";
}

// OCCF

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &ref) { *this = ref; }

PmergeMe& PmergeMe::operator=(const PmergeMe &ref)
{
	if (this != &ref)
	{
		// this->type = ref.type; //YOU CAN CHANGE THIS IF YOU NEED!!!
	}
	return *this;
}

bool operator<(const Pair& left, const Pair& right) { return left.a < right.a; }
