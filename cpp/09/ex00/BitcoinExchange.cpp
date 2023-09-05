#include "BitcoinExchange.hpp"

void	BitcoinExchange::parseDate(std::string date)
{
	std::stringstream	dt(date.c_str());
	int					year, month, day;
	char				delimiter;
	std::string			isEmpty;

	dt >> year;
	// std::cout << "Year : " << year << " / ";
	if (year < 1900 || year > 9999)
		throw ParseError();
	dt >> delimiter;
	// std::cout << "Delimiter : " << delimiter << " / ";
	if (delimiter != '-')
		throw ParseError();
	dt >> month;
	// std::cout << "Month : " << month << " / ";
	if (month < 1 || month > 12)
		throw ParseError();
	dt >> delimiter;
	if (delimiter != '-')
		throw ParseError();
	// std::cout << "Delimiter : " << delimiter << " / ";
	dt >> day;
	// std::cout << "Day : " << day << " / ";
	if ((day < 1 || day > 31))
		throw ParseError(); // (1 3 5 7 8 10 12) -> 31 // 2 윤달 // 46911 -> 30
	else if (month == 2)
	{
		if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) 
		{
			if (day > 29)
				throw ParseError(); // 윤년인 경우
		}
		else  // 윤년 아닌 경우
		{
			if (day > 28)
				throw ParseError();
		}
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
		throw ParseError();
	dt >> isEmpty;
	// std::cout << "isEmpty : " << isEmpty << '\n';
	if (!isEmpty.empty())
		throw ParseError();
}

float	BitcoinExchange::parseFloat(std::string numString)
{
	int		dot = 0;
	float	fl;

	for (size_t i = 0; i < numString.size(); i++)
	{
		if (numString[i] == '.')
		{
			dot++;
			continue ;
		}
		if ((dot > 1) || (numString[i] < '0' || numString[i] > '9'))
			throw ParseError();
	}

	std::stringstream flo(numString);
	flo >> fl;
	// std::cout << "num : " << fl << " / ";
	if (fl < 0 || fl > 1000)
		throw ParseError();
	return fl;
}

void	BitcoinExchange::parseLine(std::string line)
{
	std::stringstream	ln(line.c_str());
	std::string			dateString, numString, isEmpty;
	char				delimiter;
	float				fl;
	
	ln >> dateString;
	// std::cout << "Date String : " << dateString << " / ";
	parseDate(dateString); 
	ln >> delimiter;
	// std::cout << "Delimiter : " << delimiter << " / ";
	if (delimiter != '|')
		throw ParseError();
	ln >> numString;
	// std::cout << "num String : " << numString << " / ";
	fl = parseFloat(numString);
	ln >> isEmpty;
	// std::cout << "ISEMPTY : " << isEmpty << '\n';
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
		if (token[10] != ' ' || token[12] != ' ')
			throw ParseError();
		parseLine(token);
	}
}

void	BitcoinExchange::parseCsv()
{
	std::ifstream	data("data.csv");
	std::string		token;

	if (data.fail())
		throw FileError();
	
	std::getline(data, token);
	if (token != "data,exchange_rate")
		throw ParseError();		
}

void    BitcoinExchange::show(std::string file)
{
	try {
		parseCsv();
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
