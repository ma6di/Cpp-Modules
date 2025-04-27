
#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{

	if (argc != 3)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	const std::string& filename1 = argv[1];
	const std::string& filename2 = argv[2];
	std::map<std::string, float> sourceDataMap;

	try 
	{
		ValidateSouceFileFormat(filename1);
		processSourceDataBaseFile(filename1,sourceDataMap);
		processResultFile(filename2, sourceDataMap);
    } 
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl; // Output the error message
        return 1;
    }
}