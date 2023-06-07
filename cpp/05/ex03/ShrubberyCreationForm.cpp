#include "ShrubberyCreationForm.hpp"
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
	if (executor.getGrade() < 1 || executor.getGrade() > 150)
		return ;
	try
	{
		executable(executor); 
		std::ofstream	ofs("<" + getName() + ">_shrubbery", std::ofstream::out | std::ofstream::trunc);
		if (!ofs.good())
			throw FileOpenErrorException();
		std::string shrubbery =
		"               ,@@@@@@@,\n"
		"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
		"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
		"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
		"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
		"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
		"   `&%\\ `|/%&'    |.|        \\ '|8'\n"
		"       |o|        | |         | |\n"
		"       |.|        | |         | |\n"
		"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";
		
		ofs<<shrubbery;
		ofs.close();
		std::cout<<BOLDYELLOW<<"--------------------------------------------------------"<<RESET<<std::endl;
		std::cout<<BOLDCYAN<<executor.getName()<<RESET<<" executed "<<BOLDGREEN<<this->getType()<<RESET<<std::endl;
		std::cout<<BOLDYELLOW<<"--------------------------------------------------------"<<RESET<<std::endl;
	}
	catch (std::exception &e)
	{
		std::cout<<BOLDRED<<e.what()<<RESET<<std::endl;
	}
}
