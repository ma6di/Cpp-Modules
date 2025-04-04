#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		contact_count;
		int		next_index;

	public:
		PhoneBook(); //constructor declaration
		void add_contact();
		void search_contacts() const;
		void display_contact(int index) const;
};

#endif
