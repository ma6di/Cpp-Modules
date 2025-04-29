
#pragma once

# include <iostream>
# include <fstream>
# include <string>
# include <sstream>
# include <map>
# include <cstdlib>

//all checks
class BitcoinExchange
{
	private:
		std::string _exchangeRateDatabase;
		std::string _inquiryDatabase;
		std::map<std::string, float> _sourceDataMap;

		void processExchangeRateDatabase();
		void processInquiryFile() const;
		void validateExchangeRateDatabase() const;

	public: 
		BitcoinExchange(const std::string& inquiryDatabase);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
};


