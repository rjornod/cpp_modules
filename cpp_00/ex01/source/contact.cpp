#include "../include/Contact.hpp"

void Contact::setFirstName(const std::string name) 
{
    _firstName = name;
}

void Contact::setLastName(const std::string lastname)
{
	_lastName = lastname;
}

void Contact::setNickname(const std::string nick)
{
	_nickname = nick;
}

void Contact::setDarkestSecret(const std::string secret)
{
	_darkestSecret = secret;
}

void Contact::setPhoneNumber(const std::string number)
{
	_phoneNumber = number; 
}

std::string Contact::getFirstName() const
{
	return _firstName;
}

std::string Contact::getLastName() const
{
	return _lastName;
}

std::string Contact::getNickname() const
{
	return _nickname;
}

std::string Contact::getDarkestSecret() const
{
	return _darkestSecret;
}

std::string Contact::getPhoneNumber() const
{
	return _phoneNumber;
}