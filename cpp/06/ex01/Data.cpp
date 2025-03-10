#include "Data.hpp"

void	initData(Data &d)
{
	d.password = "Seoul";
	d.key = 4242;
	d.frac = 4.2f;
	d.dot = 4.242;
}

std::ostream&	operator<<(std::ostream &os, const Data &d)
{
	os<<BOLDYELLOW<<"Password : "<<RESET<<d.password<<std::endl;
	os<<BOLDYELLOW<<"Key : "<<RESET<<std::dec<<d.key<<std::endl;
	os<<BOLDYELLOW<<"Fraction : "<<RESET<<d.frac<<std::endl;
	os<<BOLDYELLOW<<"Dot : "<<RESET<<d.dot;
	return (os);
}
