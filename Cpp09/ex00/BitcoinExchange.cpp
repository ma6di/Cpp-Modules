
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& inquiryDatabase)
    : _exchangeRateDatabase("data.csv") ,_inquiryDatabase(inquiryDatabase)
{
    validateExchangeRateDatabase();
    processExchangeRateDatabase();
    processInquiryFile();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) :
    _exchangeRateDatabase(other._exchangeRateDatabase),
    _inquiryDatabase(other._inquiryDatabase),
    _sourceDataMap(other._sourceDataMap) {}

// Copy assignment operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _exchangeRateDatabase = other._exchangeRateDatabase;
        _inquiryDatabase = other._inquiryDatabase;
        _sourceDataMap = other._sourceDataMap;
    }
    return *this;
}

void BitcoinExchange::validateExchangeRateDatabase() const {
	size_t pos = _exchangeRateDatabase.find(".csv");
	if (pos == std::string::npos || pos + 4 != _exchangeRateDatabase.length()) {
		throw std::invalid_argument("Error: Wrong file format. Expected a .csv file.");
	}
}

void BitcoinExchange::processExchangeRateDatabase() {
	std::ifstream inquiryFile(_exchangeRateDatabase.c_str());
	if (!inquiryFile.is_open()) {
		throw std::ios_base::failure("Error: Could not open input file.");
	}

	std::string line;
	std::getline(inquiryFile, line); // skip the header line

	while (std::getline(inquiryFile, line)) {
		std::istringstream ss(line);
		std::string date, rateStr;

		if (std::getline(ss, date, ',') && std::getline(ss, rateStr))
		{
			try
			{
				float rate = std::atof(rateStr.c_str());
				_sourceDataMap[date] = rate;
			}
			catch (std::exception& e)
			{
				std::cerr << "Warning: Invalid rate value on line: " << line << "\n";
			}
		}
		else
		{
			std::cerr << "Warning: Malformed line: " << line << "\n";
		}
	}
	inquiryFile.close();
}

bool isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int getDaysInMonth(int month, int year)
{
    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30,
                                       31, 31, 30, 31, 30, 31 };

    if (month == 2 && isLeapYear(year))
        return 29;

    if (month < 1 || month > 12)
        return -1; // invalid month

    return daysInMonth[month - 1];
}

bool isValidDate(const std::string& inquiryDate) {
	if (inquiryDate.length() != 10 || inquiryDate[4] != '-' || inquiryDate[7] != '-')
		return false;
	int year, month, day;
	try {
		std::string yearStr = inquiryDate.substr(0, 4);
		year = std::atoi(yearStr.c_str());
		std::string monthStr = inquiryDate.substr(5, 2);
		month = std::atoi(monthStr.c_str());
		std::string dayStr = inquiryDate.substr(8, 2);
		day = std::atoi(dayStr.c_str());
	} catch (...) {
		return false;
	}

	if (year < 1 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	int maxDay = getDaysInMonth(month, year);
	return day <= maxDay;
}

bool isValidValue(const std::string& valueStr, float& value) {
	try {
		bool dotSeen = false;
		size_t i = 0;

		// Allow optional + or - at the beginning
		if (valueStr[i] == '-')
			throw std::out_of_range("Error: not a positive number.");
		if (valueStr[i] == '+')
			i++;
		for (; i < valueStr.size(); i++)
		{
			if (valueStr[i] == '.')
			{
				if (dotSeen)
					throw std::out_of_range("Error: multiple decimal points.");
				dotSeen = true;
			}
			else if (!isdigit(valueStr[i]))
			{
				throw std::out_of_range("Error: requested value is not a number.");
			}
		}

		value = std::atof(valueStr.c_str());

		if (value < 0)
			throw std::out_of_range("Error: not a positive number.");
		if (value > 1000)
			throw std::out_of_range("Error: too large a number.");
		return true;

	} catch (const std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
	} catch (...) {
		std::cerr << "Error: invalid value." << std::endl;
	}
	return false;
}


void BitcoinExchange::processInquiryFile() const {
	std::ifstream file(_inquiryDatabase.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	if (!std::getline(file, line)) {
        std::cerr << "Error: file is empty or contains only a header." << std::endl;
        return;
    }

	while (std::getline(file, line)) {
		size_t pipePos = line.find(" | ");
		if (pipePos == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pipePos);
		std::string valueStr = line.substr(pipePos + 3);
		float value;

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		if (!isValidValue(valueStr, value)) {
			continue; // error message already printed
		}

		// Use date to find closest match in exchangeRates
		std::map<std::string, float>::const_iterator it = _sourceDataMap.lower_bound(date);
		if (it != _sourceDataMap.end() && it->first != date) {
			if (it == _sourceDataMap.begin()) {
				std::cerr << "Error: no earlier date available." << std::endl;
				continue;
			}
			--it;
		} else if (it == _sourceDataMap.end()) {
			--it;
		}

		float result = value * it->second;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
}
