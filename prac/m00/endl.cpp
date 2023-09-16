#include <iostream>
#include <unistd.h>

int        main(void)
{
    std::cout << "hello\n";
	std::fflush(stdout);
	sleep(2);
    return (0);
}
