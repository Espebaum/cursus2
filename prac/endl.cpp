#include <iostream>
#include <unistd.h>

int        main(void)
{
    std::cout << "hello\n";
	std::fflush(stdout);
	sleep(5);
    return (0);
}
