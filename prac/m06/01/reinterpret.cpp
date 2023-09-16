#include <iostream>
#include <cstdint>
#include "../00/color.hpp"

int main(void)
{
	int			num = 1;

	int			*Danger = reinterpret_cast<int*>(num);
	std::cout<<BOLDRED<<"Dangerous : " <<Danger<<std::endl;

	intptr_t	ptr = reinterpret_cast<intptr_t>(&num);
	int			*dPtr = reinterpret_cast<int*>(ptr);

	std::cout<<BOLDWHITE<<"num : "<<num<<'\n'<<"copied num : "<<*dPtr<<std::endl;
	std::cout<<BOLDYELLOW<<"num pointer : "<<&num<<'\n' \
		<<BOLDMAGENTA<<"Serialized : "<<ptr<<'\n'\
		<<BOLDYELLOW<<"Serialized hex : "<<std::hex<<"0x"<<ptr<<'\n' \
		<<"Deserialized copied num pointer : "<<dPtr<<std::endl;
	return 0;
}
