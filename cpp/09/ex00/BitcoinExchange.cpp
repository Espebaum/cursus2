#include "BitcoinExchange.hpp"

// HERE PRINT VALUE //

void	BitcoinExchange::printValue()
{
	double		sum;
	std::string date = inputDate;
	float		val = inputFloat;

	if (state == BAD_INPUT)
		std::cout << "Error: bad input => " << badInput << std::endl;
	else if (state == NOT_POSITIVE)
		std::cout << "Error: not a positive number." << std::endl;
	else if (state == TOO_LARGE)
		std::cout << "Error: too large a number." << std::endl;
	else
	{
		std::map<std::string, float>::iterator	it;
		it = csvPairs.find(date);
		if (it != csvPairs.end())
			sum = it->second * val;
		else
		{
			it = csvPairs.lower_bound(date);
			if (it == csvPairs.begin()) {
				std::cout << "Error : bad input => " << date << std::endl;
				return;
			}
			--it;
			sum = it->second * val;
		}
		std::cout << date << " => " << val << " = " << std::setprecision(2) << sum << '\n';
	}
}

void	BitcoinExchange::clearValues()
{
	inputDate.clear();
	inputFloat = 0;
	state = 0;
	badInput.clear();
}

// HERE PARSE INPUT FILE //

void	BitcoinExchange::parseInputDate(std::string date)
{
	std::stringstream	dt(date.c_str());
	int					year, month, day;
	char				delimiter;
	std::string			isEmpty;

	if (date.size() != 10)
		state = BAD_INPUT;

	dt >> year;
	if (year < 1900 || year > 9999)
		state = BAD_INPUT; // Error: bad input

	dt >> delimiter;
	if (delimiter != '-')
		state = BAD_INPUT; // Error: bad input

	dt >> month;
	if (month < 1 || month > 12)
		state = BAD_INPUT; // Error: bad input

	dt >> delimiter;
	if (delimiter != '-')
		state = BAD_INPUT; // Error: bad input

	dt >> day;
	if ((day < 1 || day > 31))
		state = BAD_INPUT; // Error: bad input

	else if (month == 2)
	{
		if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) 
		{
			if (day > 29)
				state = BAD_INPUT; // Error: bad input
		}
		else
		{
			if (day > 28)
				state = BAD_INPUT; // Error: bad input
		}
	}

	else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
		state = BAD_INPUT; // Error: bad input
	
	if (state == BAD_INPUT)
	{
		badInput = date;
		if (badInput.empty())
			badInput = "Empty Value";
	}

	dt >> isEmpty;
	if (!isEmpty.empty())
	{
		if (badInput.empty()) badInput = isEmpty;
		state = BAD_INPUT; // Error: bad input
	}
}


void	BitcoinExchange::parseInputFloat(std::string numString)
{
	char	*end;
	float	fl;
	double	db = std::strtod(numString.c_str(), &end);

	if (db == 0.0 && !std::isdigit(numString[0]))
		state = BAD_INPUT;

	if (*end != '\0' && std::strcmp(end, "f"))
		state = BAD_INPUT;

	if (badInput.empty())
	{
		if (state == 0)
		{
			std::stringstream flo(numString);
			flo >> fl;
			inputFloat = fl;
		}
		else
			badInput = numString;	
	}
}

void	BitcoinExchange::parseInputLine(std::string line)
{
	std::stringstream	ln(line.c_str());
	std::string			dateString, numString, isEmpty;
	char				delimiter;
	int					space = 0;

	for (size_t i = 0; i < line.size(); i++)
	{
		if (line[i] == ' ')
			space++;
		if (space > 2)
		{
			state = BAD_INPUT;
			badInput = "Invalid format";
			return ;
		}
	}

	ln >> dateString;
	parseInputDate(dateString);
	inputDate = dateString;

	ln >> delimiter;
	if (delimiter != '|')
	{
		if (badInput.empty()) badInput = delimiter;
		state = BAD_INPUT;
	}

	ln >> numString;
	if (numString.empty())
	{
		if (badInput.empty()) badInput = "Empty float";
		state = BAD_INPUT;
	}

	parseInputFloat(numString);
	if (inputFloat < 0)
		state = NOT_POSITIVE; // Error: not a positive number
	else if (inputFloat > 1000)
		state = TOO_LARGE; // Error: too large a number.

	ln >> isEmpty;
	if (!isEmpty.empty())
		state = BAD_INPUT; // Error: bad input
}

void	BitcoinExchange::parseFile(std::string file)
{
	std::ifstream		input(file);
	std::string			token;

	if (input.fail())
		throw FileError();

	std::getline(input, token);
	if (token != "date | value")
		throw InputError();

	while (std::getline(input, token))
	{
		parseInputLine(token);
		printValue();
		clearValues();
	}
	input.close();
}

// HERE PARSE CSV //

void	BitcoinExchange::parseCsvDate(std::string date)
{
	std::stringstream	dt(date.c_str());
	int					year, month, day;
	char				delimiter;
	std::string			isEmpty;

	dt >> year;
	if (year < 1900 || year > 9999)
		throw DateError();

	dt >> delimiter;
	if (delimiter != '-')
		throw DateError();

	dt >> month;
	if (month < 1 || month > 12)
		throw DateError();

	dt >> delimiter;
	if (delimiter != '-')
		throw DateError();

	dt >> day;
	if ((day < 1 || day > 31))
		throw DateError(); // (1 3 5 7 8 10 12) -> 31 // 2 leap year // 46911 -> 30

	else if (month == 2)
	{
		if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) 
		{
			if (day > 29)
				throw DateError(); // leap year
		}
		else
		{
			if (day > 28)
				throw DateError(); // non leap year
		}
	}

	else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
		throw DateError();

	dt >> isEmpty;
	if (!isEmpty.empty())
		throw DateError();
}

void	BitcoinExchange::parseDataLine(std::string line)
{
	std::stringstream	ln(line.c_str());
	std::string			dateString, numString, isEmpty;
	char				*end;
	double				db;

	std::getline(ln, dateString, ',');
	parseCsvDate(dateString);

	ln >> numString;

	db = std::strtod(numString.c_str(), &end);
	if (db == 0.0 && !std::isdigit(numString[0]))
		throw CsvError();

	if (*end != '\0' && std::strcmp(end, "f"))
		throw CsvError();

	ln >> isEmpty;
	if (!isEmpty.empty())
		throw CsvError();

	csvPairs[dateString] = db;
}

void	BitcoinExchange::parseCsv()
{
	std::ifstream	data("data.csv");
	std::string		token;

	if (data.fail())
		throw FileError();
	
	std::getline(data, token);
	if (token != "date,exchange_rate")
		throw CsvError();
	while (std::getline(data, token))
	{
		if (token[4] != '-' || token[7] != '-' || token[10] != ',')
			throw CsvError();
		parseDataLine(token);
	}
	data.close();
}

void    BitcoinExchange::show(std::string file)
{
	try {
		parseCsv();
		parseFile(file);
	} catch (std::exception &e) {
		std::cout << BOLDRED << e.what() << RESET << '\n';
	}
}

// EXCEPTIONS //

const char* BitcoinExchange::InputError::what() const throw()
{
	return "Invalid format in Input";
}

const char* BitcoinExchange::CsvError::what() const throw()
{
	return "Invalid format in Csv";
}

const char* BitcoinExchange::DateError::what() const throw()
{
	return "Invalid format in date";
}

const char* BitcoinExchange::FileError::what() const throw()
{
	return "Error: could not open file";
}

// OCCF //

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) { *this = ref; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &ref)
{
	if (this != &ref) 		
	{
		this->csvPairs = ref.csvPairs;
		this->inputDate = ref.inputDate;
		this->inputFloat = ref.inputFloat;
		this->state = ref.state;
		this->badInput = ref.badInput;
	}
    return *this;
}
