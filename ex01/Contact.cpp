#include "Contact.hpp"

void Contact::set_first_ame()
{
    std::cout << "Enter First Name: ";
    std::getline(std::cin, first_name);
}

void Contact::set_last_name()
{
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, last_name);
}

void Contact::set_nickname()
{
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nickname);
}

void Contact::set_phone_number()
{
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phone_number);
}

void Contact::set_darkest_secret()
{
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkest_secret);
}

std::string Contact::get_first_name() const
{
    return (first_name);
}

std::string Contact::get_last_name() const
{
    return (last_name);
}

std::string Contact::get_nickname() const
{
    return (nickname);
}

std::string Contact::get_phone_number() const
{
    return (phone_number);
}

std::string Contact::get_darkest_secret() const
{
    return (darkest_secret);
}

std::string Contact::get_first_name_truncated() const
{
    if (first_name.length() > 10)
        return (first_name.substr(0, 9) + ".");
    else
        return (first_name);
}

std::string Contact::get_last_name_truncated() const
{
	if (last_name.length() > 10)
    	return (last_name.substr(0, 9) + ".");
	else
		return (last_name);
}

std::string Contact::get_nickname_truncated() const
{
	if (nickname.length() > 10 )
		return (nickname.substr(0, 9) + ".");
	else
		return (nickname);
}
