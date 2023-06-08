#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

#define	PPF			"PresidentialPardonForm"
#define PPF_SIGN	25
#define PPF_EXEC	5

class PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm(); // Function that only works IN member function
	public:
		// Functions in OCCF
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& ref);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);

		// Other Function
		void	execute(Bureaucrat const &executor) const;
};

#endif
