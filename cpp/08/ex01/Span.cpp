#include "Span.hpp"

const char*	Span::VectorSizeError::what() const throw()
{
	return "Cannot get Span because vector's size is not over 2";
}

Span::Span() {}

Span::Span(unsigned int N) : len(N) {}

Span::~Span() {}

Span::Span(const Span &ref) { *this = ref; }

Span& Span::operator=(const Span &ref)
{
	if (this != &ref)
	{	
		this->len = ref.getLen();
		this->array.clear();
		for (int i = 0; i < getLen(); i++)
			this->array[i] = ref.array[i];
	}
	return (*this);
}

std::vector<int>::iterator	Span::getBegin()
{
    return array.begin();
}

std::vector<int>::iterator	Span::getEnd()
{
    return array.end();
}

int	Span::getSize() const { return this->array.size(); }

int	Span::getLen() const { return this->len; }

void    Span::addNumber(int N)
{
	try {
		if (getSize() >= len)
			throw std::bad_alloc();
		this->array.push_back(N);
	} catch (std::bad_alloc &e) {
		std::cout<<"Cannot allocate "<<BOLDRED<<N<<BOLDWHITE", "<<BOLDCYAN<<e.what()<<RESET<<std::endl;
	}
}

int	Span::longestSpan()
{
	if (getSize() < 2)
		throw	Span::VectorSizeError();
	
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> p = std::minmax_element(getBegin(), getEnd());
	
	int min = *(p.first);
	int max = *(p.second);
	
	return (max - min);
}

int	Span::shortestSpan()
{
	if (getSize() < 2)
		throw	Span::VectorSizeError();

	std::vector<int> tmp(this->array);
	sort(tmp.begin(), tmp.end());
	std::vector<int> span;

	for (int i = 0; i < static_cast<int>(this->array.size()) - 1; i++)
	{
		int	num = std::abs(tmp[i + 1] - tmp[i]);
		span.push_back(num);
	}

	int min = *(std::min_element(span.begin(), span.end()));
	
	return (min);
}
