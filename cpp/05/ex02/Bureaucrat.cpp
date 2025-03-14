#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &ref) : name(ref.getName()), grade(ref.getGrade()) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &ref)
{
	if (this != &ref)
	{
		*(const_cast<std::string*>(&this->name)) = ref.getName();
		this->grade = ref.getGrade();
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
	if (ref.getIndicator() == 1)
		std::cout << BOLDBLUE << this->getName() << BOLDCYAN << " signed " \
		<< BOLDGREEN << ref.getName() << RESET << std::endl;
	else
		std::cout << BOLDBLUE << this->getName() << BOLDRED << " couldn't sign " \
		<< BOLDGREEN << ref.getName() << BOLDMAGENTA << \
		" because its grade was not that high to sign the Form..." << RESET << std::endl;
}

void	Bureaucrat::executeForm(AForm const &ref)
{
	ref.execute(*this);
}

std::ostream&	operator<<(std::ostream &os, const Bureaucrat& ref)
{
	os<<BOLDBLUE<<ref.getName()<<BOLDCYAN<<", bureaucrat grade "<< \
	BOLDGREEN<<ref.getGrade()<<BOLDWHITE<<"."<<RESET;
	return (os);
}
