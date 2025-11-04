#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

//_contact is a private member with a fixed array with 8 slots. each slot is an entry in phonebook

class PhoneBook {
	private:
		Contact _contact[8];
	public:
		void 	addContact(int index);
		void	searchContact();
};

#endif