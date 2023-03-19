#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

#define RESET   "\033[0m"		/* Reset Color */
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

class Fixed
{
	private:
		int fixed;
		static const int fraction = 8;
	public:
		Fixed();
		Fixed(const Fixed &origin);
		Fixed &operator=(const Fixed &origin);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif
