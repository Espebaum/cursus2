#include <iostream>
#include <cstdint>
#include "../00/color.hpp"

int main(void)
{
	int num = 100;
	intptr_t	i = reinterpret_cast<intptr_t>(&num);
	intptr_t*	pi = reinterpret_cast<intptr_t*>(&num);

	std::cout<<BOLDWHITE<<"num : "<<num<<RESET<<std::endl;
	std::cout<<BOLDBLUE<<"&num(int*) : "<<&num<<RESET<<std::endl;
	std::cout<<BOLDMAGENTA<<"intptr_t : "<<i<<RESET<<std::endl;
	std::cout<<BOLDBLUE<<"Hexed intptr_t : "<<std::hex<<"0x"<<i<<RESET<<std::endl;
	std::cout<<BOLDBLUE<<"intptr_t* : "<<pi<<RESET<<std::endl;
	std::cout<<BOLDMAGENTA<<"*(intptr_t*) : "<<*pi<<RESET<<std::endl;
	std::cout<<BOLDMAGENTA<<"Dec *(intptr_t*) : "<<std::dec<<*pi<<RESET<<std::endl;
	std::cout<<BOLDRED<<"&intptr_t : "<<&i<<RESET<<std::endl;
	std::cout<<BOLDYELLOW<<"intptr_max : "<<std::dec<<INTPTR_MAX<<RESET<<std::endl;

	int		*dp_num = reinterpret_cast<int*>(pi);
	int		*d_num = reinterpret_cast<int*>(i);
	std::cout<<BOLDBLUE<<"DeSerial &num : "<<dp_num<<RESET<<std::endl;
	std::cout<<BOLDWHITE<<"DeSerial num : "<<*dp_num<<RESET<<std::endl;
	std::cout<<BOLDBLUE<<"DeSerial &num : "<<d_num<<RESET<<std::endl;
	std::cout<<BOLDWHITE<<"DeSerial num : "<<*d_num<<RESET<<std::endl;
}
