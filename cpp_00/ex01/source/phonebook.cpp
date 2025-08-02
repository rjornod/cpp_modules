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

void	search_contact(PhoneBook &phonebook)
{
	int			index;
	int 		i; 

	for (i = 0; i < 8 && !phonebook.contact[i].firstName.empty(); i++)
	{
		std::cout << "|         " << i << "|";
		if (phonebook.contact[i].firstName.length() > 10)
			std::cout << phonebook.contact[i].firstName.substr(0,9) << ".|";
		else
		{
			int len = phonebook.contact[i].firstName.length();
			for (int i = 0; i < 10 - len; i++)
				std::cout << " ";
			std::cout << phonebook.contact[i].firstName << "|";
		}
		std::cout << phonebook.contact[i].lastName << " | ";
		std::cout << phonebook.contact[i].nickname << "|\n";
	}
	std::cout << "which contact do you want to search?\n";
	while (!(std::cin >> index))
	{
		std::cout << "Invalid input\n";
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
		std::cout << phonebook.contact[index].firstName << "\n";
		std::cout << phonebook.contact[index].lastName << "\n";
		std::cout << phonebook.contact[index].nickname << "\n";
		std::cout << phonebook.contact[index].phoneNumber << "\n";
		std::cout << phonebook.contact[index].darkestSecret << "\n";
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