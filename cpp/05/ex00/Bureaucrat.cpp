#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &ref) {*this = ref;}

//Cannot overload operator= properly because of constant member variable
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &ref)
{
	this -> grade = ref.getGrade();
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade()
{
	this->grade -= 1;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade()
{
	this->grade += 1;
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high...");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too Low...");
}
