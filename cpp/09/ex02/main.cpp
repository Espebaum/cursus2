#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Error" << std::endl;
        return 0;
    }

    try {
        PmergeMe    p;
        p.parse(argv);
        p.vecSort();
        p.deqSort();
    } catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
