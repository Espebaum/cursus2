#include "Global.hpp"
#include "static1.hpp"
#include "static2.hpp"
using namespace std;

int	main()
{
	cout<<BOLDYELLOW<<"G_val : "<<g_val<<", "<<"S_val : "<<s_val<<' '<<"in Main function Line : "<<__LINE__<<RESET<<endl;
	
	File1::SetVariables(3);
	cout<<BOLDYELLOW<<"G_val : "<<g_val<<", "<<"S_val : "<<s_val<<' '<<"in Main function Line : "<<__LINE__<<RESET<<endl;

	File2::SetVariables(5);
	cout<<BOLDYELLOW<<"G_val : "<<g_val<<", "<<"S_val : "<<s_val<<' '<<"in Main function Line : "<<__LINE__<<RESET<<endl;
}
