#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ----  Functions in OCCF ---- //
AForm::AForm() \
	: type("Unknown"), name("Default"), indicator(0), gradeSigned(150), gradeExecute(150) {}

AForm::AForm(std::string name, int signGrade, int executeGrade) \
	: type("Unknown"), name(name), indicator(0), gradeSigned(signGrade), gradeExecute(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &ref) \
	: name(ref.getName()), indicator(ref.getIndicator()), \
		gradeSigned(ref.getGradeSigned()), gradeExecute(ref.getGradeExecute()) {}

AForm& AForm::operator=(const AForm &ref)
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

// ---- Other Functions ---- //
void	AForm::setType(const std::string type_)
{
	*(const_cast<std::string*>(&(this->type))) = type_; 
}

std::string AForm::getType() const
{
	return (this->type);
}

std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getIndicator() const
{
	return (this->indicator);
}

int AForm::getGradeSigned() const
{
	return (this->gradeSigned);
}

int AForm::getGradeExecute() const
{
	return (this->gradeExecute);
}

void	AForm::beSigned(const Bureaucrat &ref)
{
	int	grade = ref.getGrade();

	if (grade < 1 || grade > 150)
		return;
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		if ((grade <= this->getGradeSigned()))
			this->indicator = 1;
	}
	catch (std::exception &e)
	{
		std::cout<<BOLDRED<<e.what()<<RESET<<std::endl;
	}
}

// ---- Exceptions ---- //
const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Form's grade is too high to be signed");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Form's grade is too low to be signed");
}

const char *AForm::ExecutorLowToExecute::what(void) const throw()
{
	return ("Executor's grade was too low to execute the Form");
}

const char *AForm::DoesNotSignedException::what(void) const throw()
{
	return ("This form has not been signed");
}

const char *AForm::FileOpenErrorException::what(void) const throw()
{
	return ("File open error!");
}

void	AForm::executable(const Bureaucrat &executor) const
{
	int B_grade = executor.getGrade();

	if (this->indicator == 0)
		throw AForm::DoesNotSignedException();
	if (B_grade > this->gradeExecute || B_grade < 1)
		throw AForm::ExecutorLowToExecute();
}

// ---- Overloading ostream operator ---- //
void	printLine(int line)
{
	for (int i = 0; i < line; i++)
	{
		std::cout<<BOLDMAGENTA<<"-";
	}
}

std::ostream&	operator<<(std::ostream &os, const AForm& ref)
{
	std::string	str = "  Grade required to execute : ";
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

AForm::~AForm() {}
