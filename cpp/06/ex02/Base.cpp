#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

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
