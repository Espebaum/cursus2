#include <iostream>
#include <string>
using namespace std;

class Base
{
		private:
		public:
			void what() {cout<<"Base"<<endl;}
};

class Derived : public Base
{
		public:
				void what() {cout<<"Derived"<<endl;}
};

int main(void)
{
		Base    *bp;
		Base    bas;
		Derived der;

		bp = &der;		// UP CASTING
		bas.what();		// this print "Base"
		bp->what();		// this print also "Base"
		return (0);
}
