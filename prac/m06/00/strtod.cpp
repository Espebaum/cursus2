#include <iostream>


int main(void)
{
	// nono //
	// int a = 4.0;
	// int b = 4.1;
	// int c = 4.2;

	double a = 4;
	double b = 4.1;
	double c = 0.4242;

	std::cout<<static_cast<float>(a)<<' '<<static_cast<float>(b)<<' '<<static_cast<float>(c)<<std::endl;

	const char *p = "+";
	const char *f = "+f";
	const char *z = "12f45";
	const char *y = "12f";
	char *p_ptr = NULL;
	char *f_ptr = NULL;
	char *z_ptr = NULL;
	char *y_ptr = NULL;
	double dp = std::strtod(p, &p_ptr);
	double df = std::strtod(f, &f_ptr);
	double dz = std::strtod(z, &z_ptr);
	double dy = std::strtod(y, &y_ptr);
	if (!(*f_ptr))
	{
		std::cout<<"NULL";
		return 0;
	}
	std::cout<<dp<<' '<<*p_ptr<<std::endl;
	std::cout<<df<<' '<<*f_ptr<<std::endl;
	std::cout<<dz<<' '<<*z_ptr<<' '<<z_ptr<<std::endl;
	std::cout<<dy<<' '<<*y_ptr<<' '<<y_ptr<<std::endl;
}
