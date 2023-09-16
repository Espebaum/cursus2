#include <iostream>
#include <string>
using namespace std;

#define RESET		"\033[0m"
#define BOLDBLACK	"\033[1m\033[30m"
#define BOLDRED		"\033[1m\033[31m"
#define BOLDGREEN	"\033[1m\033[32m"
#define BOLDYELLOW	"\033[1m\033[33m"
#define BOLDBLUE	"\033[1m\033[34m"
#define BOLDMAGENTA	"\033[1m\033[35m"
#define BOLDCYAN	"\033[1m\033[36m"
#define BOLDWHITE	"\033[1m\033[37m"

int	main(void)
{
	int	arr[0];
	
	cout<<"pointer: "<<arr<<" index_0: "<< \
		arr[0]<<' '<<" index_1: "<<arr[1]<<' ' \
		<<BOLDRED<<" size of array: "<<sizeof(arr) \
		<<RESET<<endl;
	
}
