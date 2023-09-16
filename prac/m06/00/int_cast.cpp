#include <iostream>

int main(void)
{
	double	a = 2147483999; // this value is bigger than INT_MAX

    if (a >= std::numeric_limits<int>::max()) {
        // Handle the out-of-range case
        std::cout << "Value is out of range for int." << std::endl;
    } else {
        int a1 = static_cast<int>(a);
        std::cout << a1 << std::endl;
    }

}
