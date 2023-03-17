#include "Harl.hpp"

int	main()
{
	Harl	harl;

	std::cout << BOLDWHITE << "------------------------------------------------------" << std::endl;
	std::cout << BOLDWHITE << "It seems like Harl wants to" << BOLDRED << " complain " << BOLDWHITE << \
	"about somthing..." << std::endl;
	std::cout << BOLDWHITE << "------------------------------------------------------" << std::endl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	return (0);
}
