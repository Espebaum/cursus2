#include "RPN.hpp"

// formula "8 9 * 9 - 9 - 9 - 4 - 1 +"

void	RPN::operate(std::string token)
{
	double	a, b, res;

	if (value.empty())
		throw ValueError();
	b = value.top(); value.pop();

	if (value.empty())
		throw ValueError();
	a = value.top(); value.pop();
	
	if (token == "+")
		res = a + b;
	else if (token == "-")
		res = a - b;
	else if (token == "*")
		res = a * b;
	else
		res = a / b;
	value.push(res);
}

void	RPN::readValue(std::string token)
{
	char	*end;
	double	val;

	if (token == "+" || token == "-" || token == "*" || token == "/")
	{
		operate(token);
	}
	else
	{
		val = std::strtod(token.c_str(), &end);
		if (val == 0.0 && !std::isdigit(token[0]))
			throw ValueError();
		if (*end != '\0' && std::strcmp(end, "f"))
			throw ValueError();
		if (val > 10)
			throw ValueError();
		value.push(val);
	}
}

void	RPN::split(std::string formula)
{
	std::stringstream	vals(formula);
	std::string			token;

	while (vals >> token) 
	{
		readValue(token);	
	}
	if (value.size() > 1)
		throw ValueError();
	std::cout << value.top() << std::endl;
}

void    RPN::calculate(std::string formula)
{
	try {
		split(formula);
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
}

// EXCEPTION //

const char* RPN::ValueError::what() const throw()
{
	return "Error";
}

// OCCF //

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &ref) { *this = ref; }

RPN& RPN::operator=(const RPN &ref)
{
	if (this != &ref) 		
	{
		this->input = ref.input;
		this->value = ref.value;
	}
    return *this;
}
