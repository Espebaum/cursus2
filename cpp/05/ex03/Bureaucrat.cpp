#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		this->grade = grade;
	}
	catch (std::exception &e)
	{
		this->grade = -1;
		std::cout<<e.what()<<std::endl;
	}
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &ref) : name(ref.name), grade(ref.grade) {}

//Cannot overload operator= properly because of constant member variable
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &ref)
{
	if (this != &ref)
	{
		this->grade = ref.grade;
	}
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

void	Bureaucrat::signForm(const AForm &ref)
{
	if (getGrade() < 1 || getGrade() > 150)
		return;
	if (ref.getIndicator() == 1)
		std::cout << BOLDBLUE << getName() << BOLDCYAN << " signed " \
		<< BOLDGREEN << ref.getType() << RESET << std::endl;
	else
		std::cout << BOLDBLUE << getName() << BOLDRED << " couldn't signed " \
		<< BOLDGREEN << ref.getType() << BOLDMAGENTA << \
		" because Bureaucrat's grade was not that high to sign the Form..." << RESET << std::endl;
}

std::ostream&	operator<<(std::ostream &os, const Bureaucrat& ref)
{
	if (ref.getGrade() < 1 || ref.getGrade() > 150)
		return (os);
	os<<BOLDBLUE<<ref.getName()<<BOLDCYAN<<", bureaucrat grade "<< \
	BOLDGREEN<<ref.getGrade()<<BOLDWHITE<<"."<<RESET;
	return (os);
}
