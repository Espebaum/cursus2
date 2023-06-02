#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() \
	: AForm()
{
	setType(BERY);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) \
	: AForm(target, BERY_SIGN, BERY_EXEC)
{
	setType(BERY);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref) \
	: AForm(ref) 
{
	setType(BERY);
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref) 
{
	return *(dynamic_cast<ShrubberyCreationForm*>(&(AForm::operator=(ref))));
}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream	ofs("<" + getName() + ">_shrubbery", std::ofstream::out | std::ofstream::trunc);
	//std::ofstream::out -> file to write, std::ofstream::trunc -> if it exists, erase it.
	std::string	shrubbery = "berry";
	ofs<<shrubbery;
	ofs.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
