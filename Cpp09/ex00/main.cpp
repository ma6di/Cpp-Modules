
#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{

	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <Inquiry File>" << std::endl;
		return 1;
	}

	try 
	{
		BitcoinExchange bitcoinExchange(argv[1]);
    } 
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
        return 1;
    }
}