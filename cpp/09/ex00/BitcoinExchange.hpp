#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <exception>

#define RESET		"\033[0m"
#define BOLDBLACK	"\033[1m\033[30m"
#define BOLDRED		"\033[1m\033[31m"
#define BOLDGREEN	"\033[1m\033[32m"
#define BOLDYELLOW	"\033[1m\033[33m"
#define BOLDPURPLE	"\033[1m\033[34m"
#define BOLDMAGENTA	"\033[1m\033[35m"
#define BOLDBLUE	"\033[1m\033[36m"
#define BOLDWHITE	"\033[1m\033[37m"

class BitcoinExchange 
{
	private:
		std::map<std::string, std::string>	input;
	public:
		// OCCF
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &ref);
		BitcoinExchange& operator=(const BitcoinExchange &ref);
		~BitcoinExchange();

		// functions
		void	parseInput(std::string file);
		void	parseLine(std::string line);
		void	parseDate(std::string date);

		// trigger
		void	show(std::string file);
		
		// exception
		class ParseError : public std::exception
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
