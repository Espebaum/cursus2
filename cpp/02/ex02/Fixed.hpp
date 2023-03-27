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
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

class Fixed
{
	private:
		int fixed;
		static const int fraction = 8;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &origin);
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
		bool operator>(const Fixed &ref) const;
		bool operator<(const Fixed &ref) const;
		bool operator>=(const Fixed &ref) const;
		bool operator<=(const Fixed &ref) const;
		bool operator!=(const Fixed &ref) const;
		bool operator==(const Fixed &ref) const;
		Fixed &operator=(const Fixed &ref);
		Fixed operator+(const Fixed &ref);
		Fixed operator-(const Fixed &ref);
		Fixed operator*(const Fixed &ref);
		Fixed operator/(const Fixed &ref);
		Fixed &operator++();
		const Fixed operator++(int);
		Fixed &operator--();
		const Fixed operator--(int);
		static Fixed &min(Fixed &ref1, Fixed &ref2);
		static const Fixed &min(Fixed const &ref1, Fixed const &ref2);
		static Fixed &max(Fixed &ref1, Fixed &ref2);
		static const Fixed &max(Fixed const &ref1, Fixed const &ref2);
		~Fixed();
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fix);

#endif
