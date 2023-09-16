#include <iostream>

int main(void)
{
	double a = 101.4425;

	double good_a = static_cast<int64_t>(a);

	std::cout<<"a: "<<a<<' '<<"good_a: "<<good_a<<std::endl;
}
