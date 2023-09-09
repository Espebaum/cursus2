#include "PmergeMe.hpp"

// -------- Function Sorting std::vector -------- //

void	PmergeMe::insertVecElement(int idx)
{
	int value = vecPendElement[idx];
	int	left = 0;
	int	right = vec.size();
	
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (vec[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	vec.insert(vec.begin() + left, value);
}

void	PmergeMe::mergeInsertVec()
{
	if (vec.size() == 1)
		return ;

	vec.clear();
	for (size_t i = 0; i < vecMainChain.size(); i++)
		vec.push_back(vecMainChain[i]);
	vec.insert(vec.begin(), vecPendElement[0]);

	int	idx = 1;
	while (static_cast<size_t>(vecJacobsthal[idx]) < vecPendElement.size())
	{
		for (int i = vecJacobsthal[idx] - 1; i > vecJacobsthal[idx - 1] - 1; i--)
			insertVecElement(i);
		idx++;
	}

	for (int i = vecPendElement.size() - 1; i > vecJacobsthal[idx - 1] - 1; i--)
		insertVecElement(i);
}

void	PmergeMe::devidePairs(std::vector<Pair> &pairs)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		vecMainChain.push_back(pairs[i].mainChain);
		vecPendElement.push_back(pairs[i].pendElement); 
	}
	if (vec.size() % 2 != 0)
		vecPendElement.push_back(vec.back());
}

void	PmergeMe::makePairs(std::vector<Pair> &pairs)
{
	int size = vec.size();

    if (size % 2 != 0)
        size -= 1;

    for (int i = 0; i < size; i += 2) 
	{
		Pair	pair;
		pair.mainChain = vec[i];
		pair.pendElement = vec[i + 1];
		pairs.push_back(pair);
    }
	std::sort(pairs.begin(), pairs.end());
}

void	PmergeMe::reorderVec()
{
    int size = vec.size();
    
    if (size % 2 != 0)
        size -= 1;
    
    for (int i = 0; i < size; i += 2)
        if (vec[i] < vec[i + 1])
            std::swap(vec[i], vec[i + 1]);
}

void	PmergeMe::vecSort()
{
	std::vector<Pair> pairs;
	struct timeval start, end;

	std::cout << "Before: ";
	showVec();

	gettimeofday(&start, NULL);
	reorderVec();
	makePairs(pairs);
	devidePairs(pairs);
	mergeInsertVec();
	gettimeofday(&end, NULL);

	std::cout << "After: ";
	showVec();

	long sec = end.tv_sec - start.tv_sec;
    long usec = end.tv_usec - start.tv_usec;
    double duration = (sec * 1000) + (usec / 1000.0);

    std::cout << "Time to process a range of " << vec.size() \
		<< " elements with std::vector : " << duration << "ms" << std::endl;
}

// -------- Function Sorting std::vector -------- //

void	PmergeMe::deqSort()
{
	std::deque<Pair> pairs;
	struct timeval start, end;

	gettimeofday(&start, NULL);
	reorderDeq();
	makePairs(pairs);
	devidePairs(pairs);
	mergeInsertDeq();
	gettimeofday(&end, NULL);

	long sec = end.tv_sec - start.tv_sec;
    long usec = end.tv_usec - start.tv_usec;
    double duration = (sec * 1000) + (usec / 1000.0);

    std::cout << "Time to process a range of " << vec.size() \
		<< " elements with std::deque : " << duration << "ms" << std::endl;
}

// PARSE && FILL JACOBSTHAL NUMBERS //

void	PmergeMe::fillJacobsthal()
{
	// 0 1 1 3 5 11 21 43 ...
	int	limit = vec.size();
	int idx = 0;
	int	cur = 1;

	while (cur <= limit)
	{
		vecJacobsthal.push_back(cur);
		idx++;
		int next = pow(2, idx + 1) - vecJacobsthal[idx - 1];
		cur = next;
	}

	// std::cout << "JACOBSTHAL : ";
	// for (size_t i = 0; i < vecJacobsthal.size(); i++)
	// 	std::cout << vecJacobsthal[i] << ' ';
	// std::cout << std::endl;

	std::deque<int> deq(vecJacobsthal.begin(), vecJacobsthal.end());
	deqJacobsthal = deq;
}

void    PmergeMe::parse(char **argv)
{
	std::vector<std::string>	tmp;
	int i = 1;

	while (argv[i])
		tmp.push_back(argv[i++]);
	
	char	*end;
	for (size_t i = 0; i < tmp.size(); i++) 
	{
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
	fillJacobsthal();
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

bool operator<(const Pair& left, const Pair& right) { return left.mainChain < right.mainChain; }
