#include "PhoneBook.hpp"

int main()
{
    PhoneBook	phoneBook;
    std::string command;

    std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
    while (true)
	{
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "EXIT")
		{
            std::cout << "Goodbye!" << std::endl;
            break;
        }
		else if (command == "ADD")
            phoneBook.add_contact();
        else if (command == "SEARCH")
            phoneBook.search_contacts();
        else 
            std::cout << "Invalid command. Please try again." << std::endl;
    }
    return 0;
}
