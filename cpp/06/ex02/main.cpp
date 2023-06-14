#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// void    leakcheck()
// {
//     system("leaks real");
// }

int main(void)
{
	// atexit(leakcheck);
	
	// Base	N_bp;    
	Base    *bp = generate();
	
	identify(bp);
	identify(*bp);

	// identify(&N_bp);
	// identify(N_bp);

	delete bp;

	return 0;
}
