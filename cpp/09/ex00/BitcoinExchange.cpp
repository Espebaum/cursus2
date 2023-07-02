#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref)
{
	*this = ref;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &ref)
{
	static_cast<void>(ref);
}

void    BitcoinExchange::checkCsvFile()
{
	std::ifstream   csv("data.csv");
	std::string     read;
	size_t  data_size;
	float   value;      

	if (!csv) 
	{
		std::cout << "Error: File open error!" << std::endl;
		// throw Error();
	}

	if (std::getline(csv, read).eof())
	{
		std::cout << "Error: Empty file" << std::endl;
		// throw Error();
	}

	while (std::getline(csv, read))
	{
		if (read != "date,exchange_rate")
		{
			data_size = read.find(',');
			if (validateDate(read.substr(0, data_size)) == false)
			{
				std::cout << "Error: include invalid date." << std::endl;
				// throw Error();
			}
			if (validateInput(read.substr(data_size + 1, read.length())) == false)
			{
				std::cout << "Error: include invalid value." << std::endl;
				// throw Error();
			}
			std::istringstream(read.substr(data_size + 1, read.length())) >> value;
			bitcoinData[read.substr(0, data_size)] = value; // map key에 대한 접근
		}	
	}
}

int		BitcoinExchange::validateDate(std::string s)
{
	if (s.length() != 10 || !(s[4] == '-' && s[7] == '-')) 
		return false;
	std::string			tmp;
	std::istringstream	is(s);
	int		year, month, day;
	int		idx = 0;

	while (std::getline(is, tmp, '-'))
	{
		if (idx == 0)
		{
			std::istringstream(tmp) >> year;
		}
	}
}