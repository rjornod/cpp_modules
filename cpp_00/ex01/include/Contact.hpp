#ifndef CONTACT_HPP
#define CONTACT_HPP

/*
first name, last name, nickname, phone number, and
darkest secret
*/
#include <iostream>

class Contact {
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _darkestSecret;
		std::string _phoneNumber;
	public:
		void	setFirstName(const std::string firstName);
		void	setLastName(const std::string lastName);
		void	setNickname(const std::string nickname);
		void	setDarkestSecret(const std::string secret);
		void	setPhoneNumber(const std::string number);
		
   		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getDarkestSecret() const;
		std::string getPhoneNumber() const;
};

#endif