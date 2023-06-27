#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <list>
# include <stack>

#define RESET		"\033[0m"
#define BOLDBLACK	"\033[1m\033[30m"
#define BOLDRED		"\033[1m\033[31m"
#define BOLDGREEN	"\033[1m\033[32m"
#define BOLDYELLOW	"\033[1m\033[33m"
#define BOLDBLUE	"\033[1m\033[34m"
#define BOLDMAGENTA	"\033[1m\033[35m"
#define BOLDCYAN	"\033[1m\033[36m"
#define BOLDWHITE	"\033[1m\033[37m"

// template <class _Tp, class _Container /*= deque<_Tp>*/>
// class _LIBCPP_TEMPLATE_VIS stack
// {
// public:
//     typedef _Container                               container_type;
//     typedef typename container_type::value_type      value_type;
//     typedef typename container_type::reference       reference;
//     typedef typename container_type::const_reference const_reference;
//     typedef typename container_type::size_type       size_type;
//     static_assert((is_same<_Tp, value_type>::value), "" );

// protected:
//     container_type c;

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {};
		MutantStack(const MutantStack& ref) { *this = ref; };
		MutantStack& operator=(const MutantStack& ref) 
		{
			static_cast<void>(ref);
			return (*this);
		};
		~MutantStack() {};
		
		typedef	typename MutantStack<T>::stack::container_type::iterator iterator;
		iterator	begin() { return this->c.begin(); }
		iterator	end() { return this->c.end(); }

		typedef	typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
		reverse_iterator	rbegin() { return this->c.rbegin(); }
		reverse_iterator	rend() { return this->c.rend(); }

		typedef	typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
		const_iterator	cbegin() { return this->c.cbegin(); }
		const_iterator	cend() { return this->c.cend(); }

		typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator	crbegin() { return this->c.crbegin(); }
		const_reverse_iterator	crend() { return this->c.crend(); }
};

#endif
