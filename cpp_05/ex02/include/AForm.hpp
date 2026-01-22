#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
		
	public:
		// Default Constructor
		AForm();

		//Parameterized Constructor
		AForm(std::string name, int gradeToSign, int gradeToExecute);

		// Copy Constructor
		AForm(const AForm& other);
		
		// Copy Assignment Operator
		AForm& operator=(const AForm& other) = delete;
		
		// Destructor
		virtual ~AForm();

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept;
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept;
		};

		
		virtual std::string getName() const = 0;
		bool getSignedInfo() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat& bureaucrat);
		void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& output_stream, const AForm& form);

#endif
