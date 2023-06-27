#ifndef ARRAY_TPP
# define ARRAY_TPP

#define RESET		"\033[0m"
#define BOLDBLACK	"\033[1m\033[30m"
#define BOLDRED		"\033[1m\033[31m"
#define BOLDGREEN	"\033[1m\033[32m"
#define BOLDYELLOW	"\033[1m\033[33m"
#define BOLDBLUE	"\033[1m\033[34m"
#define BOLDMAGENTA	"\033[1m\033[35m"
#define BOLDCYAN	"\033[1m\033[36m"
#define BOLDWHITE	"\033[1m\033[37m"

template<typename T>
Array<T>::Array() : len(0) 
{
	std::cout<<BOLDGREEN<<"Default Constructor operating"<<std::endl;
	this->array = new	T[this->len];
}

template<typename T>
Array<T>::Array(unsigned int n) : len(n)
{
	std::cout<<BOLDYELLOW<< "Constructing Array with size " << len << std::endl;
	this->array = new	T[this->len];
}

template<typename T>
Array<T>::Array(const Array& ref) : len(ref.size())
{
	std::cout<<BOLDBLUE<< "Copying Constructor operating" << std::endl;
	this->len = ref.size();
	this->array = new	T[this->len];
	for (size_t i = 0; i < this->len; i++)
	{
		this->array[i] = ref.array[i];
	}
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& ref)
{
	std::cout<<BOLDCYAN<<"Assigning Operator operating" << std::endl;
	if (this != &ref)
	{
		if (this->array)
			delete	this->array;
		this->len = ref.size();
		this->array = new	T[this->len];
		for (size_t i = 0; i < this->len; i++)
		{
			this->array[i] = ref.array[i];
		}
	}
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	std::cout<<BOLDRED<<"Deleting Array, size "<<this->len<<std::endl;
	delete[] this->array;
	this->array = NULL;
	this->len = 0;
}

template<typename T>
T& Array<T>::operator[](size_t i) //const인거 하나 만들기
{
	if (i >= len) 
	{
		throw IndexOutOfBound();
	}
	std::cout<<BOLDMAGENTA<<"Operator["<<i<<"]"<<": ";
	return array[i];
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return (this->len);
}

template<typename T>
const char* Array<T>::IndexOutOfBound::what() const throw()
{
	return ("Index out of Bound");
}

#endif
