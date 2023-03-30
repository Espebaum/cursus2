#include <iostream>
#include <string>

#define RESET   	"\033[0m"				/* Reset Color */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */

class Base
{	
	protected:
		std::string	base_string;
	public:
		Base();
		//Base(const Base &ref);
		//Base &operator=(const Base &ref);
		~Base();
		virtual void	whoamI();
};

class Derived : public Base 
{
	public:
		Derived();
		//Derived(const Derived &ref);
		//Derived &operator=(const Derived &ref);
		~Derived();
		void	whoamI();
};

//---------------------------------------------------------//
class First
{
	public:
		virtual void	print(){ std::cout << BOLDGREEN << "First!" << std::endl; }
		virtual ~First() { std:: cout << BOLDGREEN << "1 dismiss" << std::endl; }
};

class Second : public First
{
	public:
		virtual void	print(){ std::cout << BOLDBLUE << "Second!!" << std::endl; }	
		~Second() { std:: cout << BOLDBLUE << "2 dismiss" << std::endl; }
};

class Third : public Second
{
	public:
		virtual void	print(){ std::cout << BOLDCYAN << "Third!!!" << std::endl; }
		~Third() { std:: cout << BOLDCYAN << "3 dismiss" << std::endl; }
};
//---------------------------------------------------------//

//function Base
Base::Base()
{
	std::cout << BOLDBLUE << "Base is ready" << std::endl;
}

Base::~Base()
{
	std::cout << BOLDBLUE << "Base dismiss!!!" << std::endl;
}

void	Base::whoamI()
{
	std::cout << BOLDMAGENTA << "I am Base" << std::endl;;
}

//function Derived
Derived::Derived()
{
	std::cout << BOLDRED << "Derived is ready" << std::endl;
}

Derived::~Derived()
{
	std::cout << BOLDRED << "Derived dismiss!!!" << std::endl;
}

void	Derived::whoamI()
{
	std::cout << BOLDMAGENTA << "I am derived" << std::endl;
}

//main function
int main(void)
{
	std::cout << BOLDYELLOW << "Base start" << std::endl;
	Base	*p1;
	std::cout << BOLDYELLOW << "Derived start" << std::endl;
	Derived	c;
	p1 = &c;		// up casting
	std::cout << std::endl;

	std::cout << BOLDWHITE << "--------------------------------------------------------------------" << std::endl;
	std::cout << BOLDWHITE << "Virtual" << std::endl;
	std::cout << BOLDWHITE << "흠, p_c 는 Base 포인터니까 Base 의 whoamI()를 실행해야지" << std::endl;
	std::cout << BOLDWHITE << "잠깐. 이거 실제 Base 객체 맞아? 아니네 Derived 객체네" << std::endl;
	std::cout << BOLDWHITE << "그럼 Derived 의 whoamI 을 실행해야지" << std::endl;
	p1->whoamI();
	std::cout << BOLDWHITE << "--------------------------------------------------------------------" << std::endl;

	std::cout<<std::endl<<BOLDMAGENTA<<"다형성 확인"<<BOLDWHITE<<std::endl;
	First*	first_ptr[3] = {
		new First(),
		new Second(),
		new Third()
	};

	for (int i = 0; i < 3; i++)
		first_ptr[i]->print();

	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
	{
		delete first_ptr[i];
		std::cout << std::endl;
	}

	std::cout << std::endl << BOLDGREEN << "function ended" << std::endl;
	return (0);
}
