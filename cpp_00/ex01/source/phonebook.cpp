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
	std::cin >> phonebook.contact[i].phoneNumber;
	std::cout << "Darkest Secret?\n";
	std::cin >> phonebook.contact[i].darkestSecret;
}

void	search_contact(PhoneBook &phonebook)
{
	int			index;

	for (int i = 0; i < 8 && !phonebook.contact[i].firstName.empty(); i++)
	{
		std::cout << phonebook.contact[i].firstName << " | ";
		std::cout << phonebook.contact[i].lastName << " | ";
		std::cout << phonebook.contact[i].nickname << " | ";
		std::cout << phonebook.contact[i].phoneNumber << " | ";
		std::cout << phonebook.contact[i].darkestSecret << "\n";
	}
	std::cout << "which contact do you want to search?\n";
	std::cin >> index;
	if (index <= '0' || index >= '9')
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
			if (i == 3)
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