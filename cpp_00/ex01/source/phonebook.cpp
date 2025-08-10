#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"
#include <ctype.h>

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

void add_contact(int i, PhoneBook &phonebook)
{
	std::string	input;

	std::cout << "First name?\n";
	phonebook.contact[i].setFirstName(add_field(input));
	std::cout << "Last name?\n";
	phonebook.contact[i].setLastName(add_field(input));
	std::cout << "Nickname?\n";
	phonebook.contact[i].setNickname(add_field(input));
	std::cout << "Phone number?\n";
	phonebook.contact[i].setPhoneNumber(add_field(input));
	std::cout << "Darkest Secret?\n";
	phonebook.contact[i].setDarkestSecret(add_field(input));
}

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

void	search_contact(PhoneBook &phonebook)
{
	int			index;
	int 		i; 

	print_title();
	for (i = 0; i < 8 && !phonebook.contact[i].getFirstName().empty(); i++)
	{
		std::cout << "|         " << i << "|";
		truncate(phonebook.contact[i].getFirstName());
		truncate(phonebook.contact[i].getLastName());
		truncate(phonebook.contact[i].getNickname());
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
	if (phonebook.contact[index].getFirstName().empty() || index > 7)
		std::cout << "Contact doesn't exist\n";
	else
	{
		std::cout << "First Name: " << phonebook.contact[index].getFirstName() << "\n";
		std::cout << "Last Name:" << phonebook.contact[index].getLastName() << "\n";
		std::cout << "Nickname: " << phonebook.contact[index].getNickname() << "\n";
		std::cout << "Phone Number: " << phonebook.contact[index].getPhoneNumber() << "\n";
		std::cout << "Darkest Secret:" << phonebook.contact[index].getDarkestSecret() << "\n\n";
	}
}

int main()
{
	PhoneBook 	phonebook;
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
			add_contact(i++, phonebook);
		}
		else if (command == "SEARCH" || command == "search")
			search_contact(phonebook);
		else if (command == "EXIT" || command == "exit")
			exit(EXIT_SUCCESS);
		else
			std::cout << "Wrong command! Try again\n\n";
	}
}