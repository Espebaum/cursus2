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
		// parameter is const executor, so function must be const also.
		std::ofstream	ofs("<" + getName() + ">_shrubbery", std::ofstream::out | std::ofstream::trunc);
		// std::ofstream::out -> file to write, std::ofstream::trunc -> if it exists, erase it.
		// also (out | trunc) is a default mode of ofstream.
		// so This line opearates same without specifying the file mode.
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
	}
	catch (std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
}
