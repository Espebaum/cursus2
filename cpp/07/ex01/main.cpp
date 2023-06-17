#include "iter.hpp"

int main(void)
{
    std::string s[] = { "Java", "C++", "Python3", "Nestjs", "React" };
    int i[] = { 1, 2, 3, 4, 5 };
	char	c[] = {'a', 'b', 'c', 'd', 'e'};
	float	f[] = {1.1f, 2.1f, 3.1f, 4.1f, 5.1f};
	double	d[] = {1.2, 2.2, 3.2, 4.2, 5.2};

    size_t s_len = sizeof(s) / sizeof(std::string);
    size_t i_len = sizeof(i) / sizeof(int);
	size_t c_len = sizeof(c) / sizeof(char);
	size_t f_len = sizeof(f) / sizeof(float);
	size_t d_len = sizeof(d) / sizeof(double);

    std::cout << "----------------" << std::endl;
    std::cout << BOLDYELLOW << "Original Array s" << RESET << std::endl;
    std::cout << "----------------" << std::endl;
    iter(s, s_len, print); std::cout << std::endl;
    iter(i, i_len, print); std::cout << std::endl;
	iter(c, c_len, print); std::cout << std::endl;
	iter(f, c_len, print); std::cout << std::endl;
	iter(d, c_len, print); std::cout << std::endl;

    std::cout << BOLDGREEN << "===> Caesar Encryption plus 1" << RESET << std::endl;
    iter(s, s_len, next);
    iter(i, i_len, next);
	iter(c, c_len, next);
	iter(f, f_len, next);
	iter(d, d_len, next);

    std::cout << "----------------" << std::endl;
    std::cout << BOLDCYAN << "After Encryption" << RESET << std::endl;
    std::cout << "----------------" << std::endl;
    iter(s, s_len, print); std::cout << std::endl;
    iter(i, i_len, print); std::cout << std::endl;
	iter(c, c_len, print); std::cout << std::endl;
	iter(f, c_len, print); std::cout << std::endl;
	iter(d, c_len, print); std::cout << std::endl;

    return 0;
}
