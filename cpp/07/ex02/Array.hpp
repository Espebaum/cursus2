#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>

template<typename T>
class Array
{
	private:
		T       *array;
		size_t  len;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& ref);
		Array& operator=(const Array& ref);
		~Array();

		T&	operator[](size_t i);
		const T&	operator[](size_t i) const;
		unsigned int	size() const;		
		class	IndexOutOfBound : public std::exception
		{
			public:
				const char *what() const throw(); 
		};
};

#include "Array.tpp"

#endif
