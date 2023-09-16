#include <iostream>

class A
{
	std::string s;

	public:
		A(void)
			:	s("Base") {}

		void text(void)
		{
			std::cout << s << std::endl;
		}
};

class B : public A
{
	std::string s;

	public:
		B(void)
			:	A(), s("Derived") {}

		void text(void)
		{
			std::cout << s << std::endl;
		}
};

int main(void)
{
	B	  	b;
	A*		a_ptr = &b;
	B*		b_ptr = a_ptr;
	b_ptr->text();
	return (0);
}
