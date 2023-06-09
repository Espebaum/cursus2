#include "ScalarConverter.hpp"

// OCCF
ScalarConverter::ScalarConverter() \
	: input(""), value(0.0) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &ref) \
	: input(ref.input), value(ref.value) {};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &ref)
{
	if (this != &ref)
	{
		*(const_cast<std::string*>(&this->input)) = ref.input;
		*(const_cast<double*>(&this->value)) = ref.value;
	}
	return (*this);
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
	return (value);
}

std::string	ScalarConverter::getInput() const
{
	return (input);
}