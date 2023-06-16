#include "ScalarConverter.hpp"

bool ScalarConverter::err = false;

// OCCF
ScalarConverter::ScalarConverter() \
	: input(""), value(0.0) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &ref) \
	: input(ref.input), value(ref.value) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &ref)
{
	if (this != &ref)
	{
		*(const_cast<std::string*>(&this->input)) = ref.input;
		*(const_cast<double*>(&this->value)) = ref.value;
	}
	return (*this);
}

ScalarConverter::ScalarConverter(const std::string& _input) \
	: input(_input), value(0.0)
{
	try 
	{
		char	*ptr = NULL;
		*(const_cast<double*>(&value)) = std::strtod(input.c_str(), &ptr);
		if (value == 0.0 && (input[0] != '-' && input[0] != '+' && !std::isdigit(input[0])))
			throw::std::bad_alloc();
		if (*ptr && (std::strcmp(ptr, "f")))
			throw std::bad_alloc();
	}
	catch (std::exception &e) 
	{
		ScalarConverter::err = true;
	}
}

bool ScalarConverter::getErr() const
{
	return err;
}

double	ScalarConverter::getValue() const
{
	return value;
}

std::string	ScalarConverter::getInput() const
{
	return input;
}

void	ScalarConverter::ConvertToChar()
{
	char val = static_cast<char>(getValue());
	std::cout << BOLDYELLOW << "char : " << RESET;

	if (std::isnan(getValue()) || std::isinf(getValue()))
	{
		std::cout << "impossible" << std::endl;
	}

	else if (getValue() < 0 || getValue() > 255)
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

void	ScalarConverter::ConvertToInt()
{
	int val = static_cast<int>(getValue());
	std::cout << BOLDGREEN << "int : " << RESET;

	if (std::isnan(getValue()) || std::isinf(getValue()))
	{ 
		std::cout << "impossible" << std::endl;
	}

	else if (static_cast<long>(getValue()) > INT_MAX \
				|| static_cast<long>(getValue()) < INT_MIN)
	{
		std::cout << "impossible" << std::endl;
	}

	else
	{
		std::cout << val << std::endl;
	}
}

void	ScalarConverter::ConvertToPoint()
{
	float	fval = static_cast<float>(getValue());
	double	dval = static_cast<double>(getValue());

	if (std::isnan(getValue()) || std::isinf(getValue()))
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

void	ScalarConverter::convert()
{
	if (getErr()) {
		std::cout<<BOLDRED<< "Converting Failed (Bad Alloc)"<< std::endl;
		return;
	}
	ConvertToChar();
	ConvertToInt();
	ConvertToPoint();
}
