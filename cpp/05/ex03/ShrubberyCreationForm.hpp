#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

# define BERY		"ShrubberyCreationForm"
# define BERY_SIGN	145
# define BERY_EXEC	137

class ShrubberyCreationForm : public AForm
{
	private:
		ShrubberyCreationForm(); //Function that only works IN member function
	public:
		//Functions in OCCF
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& ref);
		~ShrubberyCreationForm() {};
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);

		//Other Function
		void	execute(Bureaucrat const &executor) const;
};

#endif
