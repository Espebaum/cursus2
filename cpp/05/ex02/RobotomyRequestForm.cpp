#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref)
{
    *this = ref;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
    if (this != &ref)
    {
        this->type = ref.type; //YOU CAN CHANGE THIS IF YOU NEED!!!
    }
}