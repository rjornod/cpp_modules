#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>

class ShrubberyCreationForm
{
public:
    // Default Constructor
    ShrubberyCreationForm();
    
    // Copy Constructor
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    
    // Copy Assignment Operator
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    
    // Destructor
    ~ShrubberyCreationForm();
};

#endif
