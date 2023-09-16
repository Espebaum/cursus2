#include <iostream>
#include <string>

// int main(void)
// {
//     const std::string str = "Thomas";
//     std::string* ptr = const_cast<std::string*>(&str);
//
//     //Line 10 causes Error!
//     // str[0] = 'Q';
//     (*ptr)[0] = 'Q';
//
//     std::cout << str[0] << ' ' << str << ' ' << *ptr << std::endl;
//
//     return 0;
// }

int main() {
	const int num = 10;
	int* p = const_cast<int*>(&num);
	*p = 20;

	printf("&num = %p, p = %p\n", &num, p);
	printf("num = %d, *p = %d\n", num, *p);


	return 0;
}

// int main(void)
// {
//     const std::string str = "Thomas";
//     std::string& ref = const_cast<std::string&>(str);
//     std::string ptr = "";
//
//     ref = ptr;
//     ptr[0] = 'Q';
//
//     std::cout << str << std::endl;
//     return 0;
// }
