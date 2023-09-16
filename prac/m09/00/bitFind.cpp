#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void)
{
	string	a = "date,exchange_rate";
	int num = a.find(',');
	cout<<"',' index: "<<num<<"\n\n";

	string	b = "2009-01-01,1";
	std::istringstream	is(b);

	string	c;
	std::getline(is, c, '-');
	cout<<c<<endl;
	std::getline(is, c, '-');
	cout<<c<<endl;
	std::getline(is, c, ',');
	cout<<c<<endl;
	std::getline(is, c, '-');
	cout<<c<<endl;

	return 0;
}
