#include <iostream>
#include <string>
using namespace std;

class Base
{
		private:
		public:
			virtual void what() {cout<<"Base"<<endl;}
};

class Derived : public Base
{
		public:
			void what() {cout<<"Derived"<<endl;}
};

int main(void)
{
		Derived	*dp1;
		Base    bas1;
		Derived der1;

		//dp1 = &bas;		
		//	=> DOWN CASTING??? => This cause ERROR!

		bas1.what();		//	=> this print "Base"
		
		dp1 = nullptr;		// Ok done:)
						
	// ---------- Another situation ---------- //
		
		Base	bas2;
		Derived	der2;
		
		Base	*bp = &der2;

		//Derived dp2 = bp;
		//	=> This cause ERROR too, but it is possible. 
		//	In this situation, We can use "DYNAMIC CAST"
		
		Derived *dp2 = dynamic_cast<Derived*>(bp);
		// we know that bp actually pointing Derived class der2.
		// so we can Downcast Base pointer bp to Derived pointer dp2.
		// and it doesn't occur error.
		// But if types are not matched, it can cause error.

		dp2->what();	// this print "Derived"

		return (0);
}
