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

// Converting Functions
char	ScalarConverter::toChar() const
{
	return static_cast<char>(value);
}

double	ScalarConverter::toDouble() const
{
	return static_cast<double>(value);
}

float	ScalarConverter::toFloat() const
{
	return static_cast<float>(value);
}

int	ScalarConverter::toInt() const
{
	return static_cast<int>(value);
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
	std::cout << BOLDYELLOW << "char : " << RESET;

	if (std::isnan(getValue()) || std::isinf(getValue()))
	{
		std::cout << "impossible" << std::endl;
	}

	else if (getValue() < 0 || getValue() > 255)
	{
		std::cout << "Non displayable" << std::endl;
	}

	else if (std::isprint(static_cast<char>(getValue())))
	{
		std::cout << "'" << static_cast<char>(getValue()) << "'" << std::endl;
	}

	else
	{
		std::cout<< "Non displayble" << std::endl;
	}
}

void	printToInt(std::ostream &os, const ScalarConverter &c)
{
	os << BOLDGREEN << "int: " << RESET; 
	if (std::isnan(c.getValue()) || std::isinf(c.getValue())) {
		os << NP << std::endl;
	} else if (c.getValue() > std::numeric_limits<int>::max() \
		|| c.getValue() < std::numeric_limits<int>::min()) {
		std::cout<<"impossible"<<std::endl;
	} else {
		os << c.toInt() << std::endl;
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
	else if (val > std::numeric_limits<int>::max() \
				|| val < std::numeric_limits<int>::min())
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << static_cast<int>(getValue()) << std::endl;
	}
}
// 이거 만들고 ConvertToPoint만들고 정리, 복습 후 평가

void	printToPoint(std::ostream &os, const ScalarConverter& c)
{
	if (std::isnan(c.getValue()) || std::isinf(c.getValue()))
	{
		os << BOLDBLUE << "float: " << RESET << c.toFloat() << "f"<<std::endl;
		os << BOLDCYAN << "double: " << RESET << c.toDouble();
		return;
	}
	if (c.toFloat() == static_cast<int64_t>(c.toFloat()))
	{
		os << BOLDBLUE << "float: " << RESET << c.toFloat() << ".0f" << std::endl;
	}
	else
	{
		os << BOLDBLUE << "float: " << RESET << std::setprecision \
		(std::numeric_limits<float>::digits10)<<c.toFloat()<<"f"<<std::endl;
	}
	if (c.toDouble() == static_cast<int64_t>(c.toDouble()))
	{
		os << BOLDCYAN << "double: " << RESET << c.toDouble() << ".0";
	}
	else
	{
		os << BOLDCYAN << "double: " << RESET << std::setprecision \
		(std::numeric_limits<float>::digits10)<<c.toFloat();	
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
}
