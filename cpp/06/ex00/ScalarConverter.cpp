#include "ScalarConverter.hpp"

// OCCF in Private Area
ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &ref) { *this = ref; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &ref)
{
	static_cast<void>(ref);
	return (*this);
}

static void	ConvertToChar(double &value)
{
	char val = static_cast<char>(value);
	std::cout << BOLDYELLOW << "char : " << RESET;

	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "impossible" << std::endl;
	}

	else if (value < 0 || value > 255)
	{
		std::cout << "Non displayable" << std::endl;
	}

	else if (std::isprint(val))
	{
		std::cout << "'" << val << "'" << std::endl;
	}

	else
	{
		std::cout<< "Non displayble" << std::endl;
	}
}

static void	ConvertToInt(double &value)
{
	int val = static_cast<int>(value);
	std::cout << BOLDGREEN << "int : " << RESET;

	if (std::isnan(value) || std::isinf(value))
	{ 
		std::cout << "impossible" << std::endl;
	}

	else if (static_cast<long>(value) > INT_MAX \
				|| static_cast<long>(value) < INT_MIN)
	{
		std::cout << "impossible" << std::endl;
	}

	else
	{
		std::cout << val << std::endl;
	}
}

static void	ConvertToPoint(double &value)
{
	float	fval = static_cast<float>(value);
	double	dval = static_cast<double>(value);

	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << BOLDBLUE << "float : " << RESET << std::showpos << fval << "f" << std::endl;
		std::cout << BOLDCYAN << "double : " << RESET << std::showpos << dval << std::endl;
		return;
	}

	if (fval == static_cast<int64_t>(fval))
	{
		std::cout << BOLDBLUE << "float : " << RESET << fval << ".0f" << std::endl;
	}

	else
	{
		std::cout << BOLDBLUE << "float : " << RESET << std::setprecision(6) << fval << "f" << std::endl;
	}

	if (dval == static_cast<int64_t>(dval))
	{
		std::cout << BOLDCYAN << "double : " << RESET << dval << ".0" << std::endl;
	}

	else
	{
		std::cout << BOLDCYAN << "double : " <<RESET << std::setprecision(15) << dval << std::endl;
	}
}

static double	ConvertInputDouble(std::string &input)
{
	double	value = 0.0;

	char	*ptr = NULL;
	*(const_cast<double*>(&value)) = std::strtod(input.c_str(), &ptr);
	if (value == 0.0 && (input[0] != '-' && input[0] != '+' && !std::isdigit(input[0])))
	{
		throw std::bad_alloc(); // std::isdigit returns 0, if char is not a number.
	}
	if (*ptr && (std::strcmp(ptr, "f"))) // if ptr and "f" are different, std::strcmp() returns 1
	{
		throw std::bad_alloc();
		// ./Convert "+", "-", "+f", "-f" stuck here
	}
	return value;
}

void	ScalarConverter::convert(std::string &input)
{
	try
	{
		double value = ConvertInputDouble(input);		
		ConvertToChar(value);
		ConvertToInt(value);
		ConvertToPoint(value);
	}
	catch (std::bad_alloc &e) 
	{
		std::cout<<BOLDRED<<e.what()<<RESET<<std::endl;
	}

	return ;
}
