#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void	identify(Base *bp)
{
	std::cout<<BOLDYELLOW<<"-------- Pointer --------"<<std::endl;

	if (A* a = dynamic_cast<A*>(bp))
	{
		std::cout << BOLDGREEN << std::setw(13) << "A" << std::endl;
	}
	else if (B* b = dynamic_cast<B*>(bp))
	{
		std::cout << BOLDGREEN << std::setw(13) << "B" << std::endl;
	}
	else if (C* c = dynamic_cast<C*>(bp))
	{
		std::cout << BOLDGREEN << std::setw(13) << "C" << std::endl;
	}
	else
	{
		std::cout << BOLDGREEN << "  Identification failed" \
		<<	std::endl;
	}

	std::cout<<BOLDYELLOW<<"-------------------------"<<RESET<<std::endl;
}

void	identify(Base &br)
{
	std::cout<<BOLDCYAN<<"------- reference -------"<<std::endl;

	try
	{
		A& a = dynamic_cast<A&>(br);
		std::cout << BOLDRED << std::setw(13) << "A" << std::endl;
		static_cast<void>(a);
	}
	catch (std::exception&)
	{
		try
		{
			B& b = dynamic_cast<B&>(br);
			std::cout << BOLDRED << std::setw(13) << "B" << std::endl;
			static_cast<void>(b);
		}
		catch (std::exception&)
		{
			try
			{
				C& c = dynamic_cast<C&>(br);
				std::cout << BOLDRED << std::setw(13) << "C" << std::endl;
				static_cast<void>(c);
			}
			catch (std::exception&)
			{
				std::cout << BOLDRED << "  Identification failed" \
				<< std::endl;            
			}
		}
	}

	std::cout<<BOLDCYAN<<"-------------------------"<<RESET<<std::endl;
}

Base*   generate(void)
{
	srand((unsigned int)time(NULL));
	int per = rand() % 9;
	
	if (per >= 0 && per <= 2)
		return new A;
	else if (per >= 3 && per <= 5)
		return new B;
	else
		return new C;
}

Base::~Base() {}
