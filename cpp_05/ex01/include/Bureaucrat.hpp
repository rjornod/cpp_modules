#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# define RED "\033[1;31m"
# define WHITE "\033[0m"
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		// Default Constructor
		Bureaucrat();

		// Parameterized Constructor
		Bureaucrat(const std::string name, int grade);
		
		// Copy Constructor
		Bureaucrat(const Bureaucrat& other);
		
		// Copy Assignment Operator
		Bureaucrat& operator=(const Bureaucrat& other) = delete;
		
		// Destructor
		~Bureaucrat();

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept;
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept;
		};

		const std::string getName() const;
		int getGrade() const;
		void incGrade();
		void decGrade();
		void signForm();
};

std::ostream& operator<<(std::ostream& output_stream, const Bureaucrat& bureaucrat);

#endif
