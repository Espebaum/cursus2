#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), indicator(0), gradeSigned(150), gradeExecute(150) {}

Form::~Form() {}

Form::Form(std::string name, int grade) : name(name), indicator(0), gradeSigned(grade), gradeExecute(grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &ref) \
	: name(ref.getName()), indicator(ref.getIndicator()), \
		gradeSigned(ref.getGradeSigned()), gradeExecute(ref.getGradeExecute()) {}

//Cannot overload operator= properly because of constant member variables
Form& Form::operator=(const Form &ref)
{
	if (this != &ref)
	{
		*(const_cast<std::string*>(&this->name)) = ref.getName();
		*(const_cast<int*>(&this->gradeSigned)) = ref.getGradeSigned();
		*(const_cast<int*>(&this->gradeExecute)) = ref.getGradeExecute();
		this->indicator = ref.indicator;
	}
	return (*this);
}

std::string Form::getName() const
{
	return (this->name);
}

bool Form::getIndicator() const
{
	return (this->indicator);
}

int Form::getGradeSigned() const
{
	return (this->gradeSigned);
}

int Form::getGradeExecute() const
{
	return (this->gradeExecute);
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Form's grade is too high to be signed");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Form's grade is too low to be signed");
}

void	Form::beSigned(const Bureaucrat &ref)
{
	int	grade = ref.getGrade();

	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
	
	if ((grade <= this->getGradeSigned()) && (grade <= this->getGradeExecute()))
		this->indicator = 1;
}

void	printLine(int line)
{
	for (int i = 0; i < line; i++)
	{
		std::cout<<BOLDMAGENTA<<"-";
	}
}

std::ostream&	operator<<(std::ostream &os, const Form& ref)
{
	std::string	str = "| Grade required to execute : ";
	int	line = str.length() + 3; 

	printLine(line);
	std::cout<<std::endl;
	os	<< BOLDCYAN << "  NAME : "<<BOLDGREEN << ref.getName() << std::endl \
		<< BOLDCYAN << "  Is SIGNED? : " << std::boolalpha << BOLDYELLOW << ref.getIndicator() << std::endl \
		<< BOLDCYAN << "  GRADE required to SIGN : " << BOLDGREEN << ref.getGradeSigned() << std::endl \
		<< BOLDCYAN << "  GRADE required to EXECUTE : " << BOLDGREEN << ref.getGradeExecute() << RESET<<std::endl;
	printLine(line);
	std::cout<<RESET;
	return (os);
}
