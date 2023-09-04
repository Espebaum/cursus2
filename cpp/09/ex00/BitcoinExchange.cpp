#include "BitcoinExchange.hpp"

void	BitcoinExchange::parseDate(std::string date)
{
	std::stringstream	dt(date.c_str());
	int	year, month, day;
	char	delimiter;

	dt >> year;
	std::cout << "Year : " << year << " / ";
	if (year < 1900 || year > 9999)
		throw ParseError();
	dt >> delimiter;
	std::cout << "Delimiter : " << delimiter << " / ";
	if (delimiter != '-')
		throw ParseError();
	dt >> month;
	std::cout << "Month : " << month << " / ";
	if (month < 1 || month > 12)
		throw ParseError();
	dt >> delimiter;
	if (delimiter != '-')
		throw ParseError();
	std::cout << "Delimiter : " << delimiter << " / ";
	dt >> day;
	std::cout << "Day : " << day << '\n';
}

void	BitcoinExchange::parseLine(std::string line)
{
	std::stringstream	ln(line.c_str());
	std::string		dateString, numString;
	std::string		delimiter;
	std::string		isEmpty;
	
	ln >> dateString;
	parseDate(dateString); 
	// std::cout << "Date String : " << dateString << '\n';
	ln >> delimiter;
	// std::cout << "Delimiter : " << delimiter << '\n';
	ln >> numString;
	// std::cout << "num String : " << numString << '\n';
	ln >> isEmpty;
	if (!isEmpty.empty())
		throw ParseError();
}

void	BitcoinExchange::parseInput(std::string file)
{
	std::ifstream		input(file);
	std::string			token;

	if (input.fail())
		throw FileError();

	std::getline(input, token);
	if (token != "date | value")
		throw ParseError();

	while (std::getline(input, token))
	{
		// std::cout << "TOKEN : " << token << '\n';
		parseLine(token);
	}
}

void    BitcoinExchange::show(std::string file)
{
	try {
		parseInput(file);
	} catch (std::exception &e) {
		std::cout << BOLDRED << e.what() << RESET << '\n';
	}
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref)
{
	*this = ref;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &ref)
{
	static_cast<void>(ref);
	return *this;
}

const char* BitcoinExchange::ParseError::what() const throw()
{
	return "Invalid format in file";
}

const char* BitcoinExchange::FileError::what() const throw()
{
	return "File open Error";
}
