#include <iostream>
using namespace std;

int main(void)
{
	string	input1;
	string	input2;

	cout<<"input1 : ";
	cin>>input1;
	cout<<"input2 : ";
	cin>>input2;

	if (input1 > input2)
	{
		cout<<"input1이 더 크다"<<' '<<input1<<endl;
	}
	else
	{
		cout<<"input2가 더 크다"<<' '<<input2<<endl;
	}
	return 0;
}
