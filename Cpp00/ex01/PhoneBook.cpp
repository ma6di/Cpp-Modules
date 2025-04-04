#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <cstdlib>

//constructor
PhoneBook::PhoneBook() 
{
	contact_count = 0;
	next_index = 0;
}


void PhoneBook::add_contact()
{
    Contact new_contact;

    new_contact.set_first_ame();
    new_contact.set_last_name();
    new_contact.set_nickname();
    new_contact.set_phone_number();
    new_contact.set_darkest_secret();

    contacts[next_index] = new_contact;

    if (contact_count < 8)
        contact_count++;
    next_index = (next_index + 1) % 8;

    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::search_contacts() const 
{
    if (contact_count == 0)
	{
        std::cout << "No contacts to display." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < contact_count; ++i)
	{
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << contacts[i].get_first_name_truncated() << "|"
                  << std::setw(10) << contacts[i].get_last_name_truncated() << "|"
                  << std::setw(10) << contacts[i].get_nickname_truncated() << std::endl;
    }

    std::cout << "Enter the index of the contact to view details: ";
    std::string input;
    std::getline(std::cin, input);

    int index = std::atoi(input.c_str());
    if (index < 0 || index >= contact_count)
        std::cout << "Invalid index." << std::endl;
	else
        display_contact(index);
}

void PhoneBook::display_contact(int index) const
{
    std::cout << "First Name: " << contacts[index].get_first_name() << std::endl;
    std::cout << "Last Name: " << contacts[index].get_last_name() << std::endl;
    std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].get_phone_number() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].get_darkest_secret() << std::endl;
}
