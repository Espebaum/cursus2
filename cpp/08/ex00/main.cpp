#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v;
	std::deque<int> d;
	std::list<int> l;

	for (int i = 0; i < 9; i++) {
		v.push_back(10 - i);
		d.push_back(10 - i);
		l.push_back(10 - i);
	}

	// vector //
	try {
		std::cout<<"-----------------------"<<std::endl;
		std::vector<int>::iterator it1 = easyfind(v, 5);        
		std::cout<<BOLDGREEN<<"value to find : "<<RESET<<*it1<<std::endl;
		std::cout<<BOLDGREEN<<"Index in vector : "<<RESET<<std::distance(v.begin(), it1)<<std::endl;
		std::cout<<"-----------------------"<<std::endl;
	} catch (std::exception &e) {
		std::cerr<<BOLDRED<<e.what()<<RESET<<std::endl;
	}
	std::cout<<std::endl;

	// deque //
	try {
		std::cout<<"-----------------------"<<std::endl;
		std::deque<int>::iterator it2 = easyfind(d, 6);
		std::cout<<BOLDCYAN<<"value to find : "<<RESET<<*it2<<std::endl;
		std::cout<<BOLDCYAN<<"Index in deque : "<<RESET<<std::distance(d.begin(), it2)<<std::endl;
		std::cout<<"-----------------------"<<std::endl;
	} catch (std::exception &e) {
		std::cerr<<BOLDRED<<e.what()<<RESET<<std::endl;
	}
	std::cout<<std::endl;

	// list //
	try {
		std::cout<<"-----------------------"<<std::endl;
		std::list<int>::iterator it3 = easyfind(l, 2);
		std::cout<<BOLDBLUE<<"value to find : "<<RESET<<*it3<<std::endl;
		std::cout<<BOLDBLUE<<"Index in list : "<<RESET<<std::distance(l.begin(), it3)<<std::endl;
		std::cout<<"-----------------------"<<std::endl;
	} catch (std::exception &e) {
		std::cerr<<BOLDRED<<e.what()<<RESET<<std::endl;
	}
}
