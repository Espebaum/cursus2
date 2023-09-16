#include <iostream>

class A
{
	std::string s;

	public:
		A(void)
			:	s("Base") {}

		virtual void text(void)
		{
			std::cout << s << std::endl;
		}

		virtual ~A() {};

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
	A	  	a;
	A*		a_ptr = &a;
	B*		b_ptr = dynamic_cast<B*>(a_ptr);
	if (!b_ptr)
		std::cout<<"cast failed"<<std::endl;
	else
		b_ptr->text();
	return (0);
}
