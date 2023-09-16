#include <iostream>
using namespace std;

int main(void)
{
	const int	e = 3;
	
	int *pe = const_cast<int*>(&e);
	
	*pe = 4;

	int	*npe = pe;
	cout<<&e<<' '<<pe<<' '<<npe<<'\n';
	cout<<e<<' '<<*pe<<' '<<*npe;
}
