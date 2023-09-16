#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <exception>
#include <iomanip>

#define RESET		"\033[0m"
#define BOLDBLACK	"\033[1m\033[30m"
#define BOLDRED		"\033[1m\033[31m"
#define BOLDGREEN	"\033[1m\033[32m"
#define BOLDYELLOW	"\033[1m\033[33m"
#define BOLDPURPLE	"\033[1m\033[34m"
#define BOLDMAGENTA	"\033[1m\033[35m"
#define BOLDBLUE	"\033[1m\033[36m"
#define BOLDWHITE	"\033[1m\033[37m"

enum ParseState
{
	BAD_INPUT = 1,
	NOT_POSITIVE = 2,
	TOO_LARGE = 3
};

class BitcoinExchange 
{
	private:
		std::map<std::string, float>	csvPairs;
		std::string						inputDate;
		float							inputFloat;
		int								state;
		std::string						badInput;

	public:
		// OCCF
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &ref);
		BitcoinExchange& operator=(const BitcoinExchange &ref);
		~BitcoinExchange();

		// functions
		void	parseCsv();
		void	parseCsvDate(std::string date);
		void	parseDataLine(std::string line);

		void	parseFile(std::string file);
		void	parseInputLine(std::string line);
		void	parseInputDate(std::string date);
		void	parseInputFloat(std::string fl);

		// trigger
		void	show(std::string file);
		void	printValue();
		void	clearValues();
		
		// exceptions
		class InputError : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class CsvError : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class DateError : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class FileError : public std::exception
		{
			public:
				const char* what() const throw();
		};
};
