#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"
#include <ctype.h>

/**
	@brief Waits for the input from the user and returns it to be added to the phonebook
	@param input what will be inputed by the user and returned to be added
*/
std::string	add_field(std::string input)
{
	do {
			std::getline(std::cin >> std::ws, input);
			if (std::cin.eof())
				exit(EXIT_FAILURE);
	}
	while (input.empty());
	return (input);
}

/*
	Prompts the user for the first name, last name, nickname, phone number and darkest secret of the contact
	A public function gets called for each prompt, allowing the private members to be set
*/
void PhoneBook::addContact(int i)
{
	std::string	input;

	std::cout << "First name?\n";
	_contact[i].setFirstName(add_field(input));
	std::cout << "Last name?\n";
	_contact[i].setLastName(add_field(input));
	std::cout << "Nickname?\n";
	_contact[i].setNickname(add_field(input));
	std::cout << "Phone number?\n";
	_contact[i].setPhoneNumber(add_field(input));
	std::cout << "Darkest Secret?\n";
	_contact[i].setDarkestSecret(add_field(input));
}

/*
	Checks if the given string has more than 10 characters
	If it does it only prints the first 9 characters and adds a . after
	If it doesnt it displays the string normally
*/
void	truncate(std::string string)
{
	if (string.length() > 10)
			std::cout << string.substr(0,9) << ".|";
	else
	{
		int len = string.length();
		for (int i = 0; i < 10 - len; i++)
			std::cout << " ";
		std::cout << string << "|";
	}
}

void print_title()
{
    std::cout << " ____  _                      ____              _    \n";
    std::cout << "|  _ \\| |__   ___  _ __   ___| __ )  ___   ___ | | __\n";
    std::cout << "| |_) | '_ \\ / _ \\| '_ \\ / _ \\  _ \\ / _ \\ / _ \\| |/ /\n";
    std::cout << "|  __/| | | | (_) | | | |  __/ |_) | (_) | (_) |   < \n";
    std::cout << "|_|   |_| |_|\\___/|_| |_|\\___|____/ \\___/ \\___/|_|\\_\\\n";
	std::cout << "\n";
	std::cout << "---------------------------------------------\n";
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|\n";
	std::cout << "---------------------------------------------\n";
}

/*
	First displays a list of first name, last name, nickname of all the registered contacts
	Then prompts the user which contact they want to see more of
	If a user specifies a non existing index or other bad input an error message will be displayed	
*/
void	PhoneBook::searchContact()
{
	int			index;
	int 		i; 

	print_title();
	for (i = 0; i < 8 && !_contact[i].getFirstName().empty(); i++)
	{
		std::cout << "|         " << i << "|";
		truncate(_contact[i].getFirstName());
		truncate(_contact[i].getLastName());
		truncate(_contact[i].getNickname());
		std::cout << "\n";
		std::cout << "---------------------------------------------\n";
	}
	std::cout << "\nwhich contact do you want to search?\n";
	while (!(std::cin >> index))
	{
		if (std::cin.eof())
			exit(EXIT_FAILURE);
		std::cout << "Invalid input, try again\n";
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
	if (std::cin.eof())
		exit(EXIT_FAILURE);
	if (index < 0 || index >= i)
	{
		std::cout << "Contact doesn't exist\n\n";
		return;
	}
	if (_contact[index].getFirstName().empty() || index > 7)
		std::cout << "Contact doesn't exist\n";
	else
	{
		std::cout << "First Name: " << _contact[index].getFirstName() << "\n";
		std::cout << "Last Name:" << _contact[index].getLastName() << "\n";
		std::cout << "Nickname: " << _contact[index].getNickname() << "\n";
		std::cout << "Phone Number: " << _contact[index].getPhoneNumber() << "\n";
		std::cout << "Darkest Secret:" << _contact[index].getDarkestSecret() << "\n\n";
	}
}

int main()
{
	PhoneBook	phonebook;
	std::string	command;
	int			i = 0;

	while (1)
	{
		std::cout << "Commands available: ADD | SEARCH | EXIT\n";
		std::cin >> command;
		if (std::cin.eof())
			exit(EXIT_FAILURE);
		std::cin.ignore(1000, '\n');
		if (command == "ADD" || command == "add")
		{
			if (i == 8)
				i = 0;
			phonebook.addContact(i++);
		}
		else if (command == "SEARCH" || command == "search")
			phonebook.searchContact();
		else if (command == "EXIT" || command == "exit")
			exit(EXIT_SUCCESS);
		else
			std::cout << "Wrong command! Try again\n\n";
	}
}