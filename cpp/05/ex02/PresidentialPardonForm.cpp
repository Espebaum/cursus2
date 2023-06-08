#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() \
	: AForm()
{
	setType(PPF);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) \
	: AForm(target, PPF_SIGN, PPF_EXEC)
{
	setType(PPF);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) \
	: AForm(ref)
{
	setType(PPF);
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
	return *(dynamic_cast<PresidentialPardonForm*>(&(AForm::operator=(ref))));
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	executable(executor);
	
	std::cout << RESET << "<" << BOLDCYAN << getName() \
	<< RESET << "> has been pardoned by " << BOLDRED << "Zafod Beeblebrox" \
	<< std::endl;
	
    std::cout<<BOLDYELLOW<<"--------------------------------------------------------"<<RESET<<std::endl;
	std::cout<<BOLDCYAN<<executor.getName()<<RESET<<" executed "<<BOLDGREEN<<this->getType()<<RESET<<std::endl;
    std::cout<<BOLDYELLOW<<"--------------------------------------------------------"<<RESET<<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}
