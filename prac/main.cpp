#include <iostream>
#include <string>
using namespace std;

int main()
{
	int val;
	cin >> val;
	cin.ignore();
	string str;
	getline(cin, str);
	cout << val << str << endl;
}
