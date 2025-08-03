#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"
#include <ctype.h>


void add_contact(int i, PhoneBook &phonebook)
{

	std::cout << "adding the " << i << " contact\n";
	std::cout << "First name?\n";
	std::cin >> phonebook.contact[i].firstName;
	std::cout << "Last name?\n";
	std::cin >> phonebook.contact[i].lastName;
	std::cout << "Nickname?\n";
	std::cin >> phonebook.contact[i].nickname;
	std::cout << "Phone number?\n";
	while (!(std::cin >> phonebook.contact[i].phoneNumber))
	{
		std::cout << "Invalid phone number, try again.\n";
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
	std::cout << "Darkest Secret?\n";
	std::cin >> phonebook.contact[i].darkestSecret;
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
}

void	search_contact(PhoneBook &phonebook)
{
	int			index;
	int 		i; 

	print_title();
	for (i = 0; i < 8 && !phonebook.contact[i].firstName.empty(); i++)
	{
		std::cout << "|         " << i << "|";
		truncate(phonebook.contact[i].firstName);
		truncate(phonebook.contact[i].lastName);
		truncate(phonebook.contact[i].nickname);
		std::cout << "\n";
	}
	std::cout << "\nwhich contact do you want to search?\n";
	while (!(std::cin >> index))
	{
		std::cout << "Invalid input, try again\n";
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
	if (index < 0 || index >= i)
	{
		std::cout << "Invalid index\n";
		return;
	}
	if (phonebook.contact[index].firstName.empty() || index > 7)
		std::cout << "Contact doesn't exist\n";
	else
	{
		std::cout << "First Name: " << phonebook.contact[index].firstName << "\n";
		std::cout << "Last Name:" << phonebook.contact[index].lastName << "\n";
		std::cout << "Nickname: " << phonebook.contact[index].nickname << "\n";
		std::cout << "Phone Number: " << phonebook.contact[index].phoneNumber << "\n";
		std::cout << "Darkest Secret:" << phonebook.contact[index].darkestSecret << "\n";
	}
}

int main()
{
	// Contact contact;
	PhoneBook 	phonebook;
	std::string	command;
	int			i = 0;

	while (1)
	{
		std::cout << "Commands available: ADD | SEARCH | EXIT\n";
		std::cin >> command;
		if (command == "ADD" || command == "add")
		{
			if (i == 8)
				i = 0;
			add_contact(i++, phonebook);
		}
		else if (command == "SEARCH" || command == "search")
		{
			search_contact(phonebook);
		}
		else if (command == "EXIT" || command == "exit")
		{
			exit(EXIT_SUCCESS);
		}
		else
			std::cout << "Wrong command! Try again\n";
	}
}