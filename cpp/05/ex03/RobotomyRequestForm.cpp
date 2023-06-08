#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() \
    : AForm()
{
    setType(ROBO);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) \
    : AForm(target, ROBO_SIGN, ROBO_EXEC)
{
    setType(ROBO);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref) \
    : AForm(ref)
{
    setType(ROBO);
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &ref) 
{
    return *(dynamic_cast<RobotomyRequestForm*>(&(AForm::operator=(ref))));
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() < 1 || executor.getGrade() > 150)
		return ;
    try
    {
        executable(executor);

        srand((unsigned int)time(NULL));
        int per = rand() % 10;
        std::cout<<RESET;

        if (per <= 4)
            std::cout<<BOLDYELLOW<<getName()<<"'s"<<BOLDCYAN \
            <<" Robotomy Surgery has been completed successfully!!!"<<std::endl;
        else
            std::cout<<BOLDRED<<getName()<<"'s"<<BOLDRED \
            <<" Robotomy Surgery has been failed..."<<std::endl;
		std::cout<<BOLDYELLOW<<"--------------------------------------------------------"<<RESET<<std::endl;
		std::cout<<BOLDCYAN<<executor.getName()<<RESET<<" executed "<<BOLDGREEN<<this->getType()<<RESET<<std::endl;
		std::cout<<BOLDYELLOW<<"--------------------------------------------------------"<<RESET<<std::endl;
    }
	catch (std::exception &e)
	{
		std::cout<<BOLDRED<<e.what()<<RESET<<std::endl;
	}
}

RobotomyRequestForm::~RobotomyRequestForm() {}
