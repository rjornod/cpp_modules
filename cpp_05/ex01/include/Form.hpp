#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
		
	public:
		// Default Constructor
		Form();

		//Parameterized Constructor
		Form(std::string name, int gradeToSign, int gradeToExecute);

		// Copy Constructor
		Form(const Form& other);
		
		// Copy Assignment Operator
		Form& operator=(const Form& other) = delete;
		
		// Destructor
		~Form();

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept;
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept;
		};

		
		std::string getName() const;
		bool getSignedInfo() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& output_stream, const Form& form);

#endif
