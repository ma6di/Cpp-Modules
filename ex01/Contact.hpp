#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:
		void set_first_ame();
		void set_last_name();
		void set_nickname();
		void set_phone_number();
		void set_darkest_secret();

		std::string get_first_name() const;
		std::string get_last_name() const;
		std::string get_nickname() const;
		std::string get_phone_number() const;
		std::string get_darkest_secret() const;

		std::string get_first_name_truncated() const;
		std::string get_last_name_truncated() const;
		std::string get_nickname_truncated() const;
};

#endif
