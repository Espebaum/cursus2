#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref)
{
    *this = ref;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
    if (this != &ref)
    {
        this->type = ref.type; //YOU CAN CHANGE THIS IF YOU NEED!!!
    }
}