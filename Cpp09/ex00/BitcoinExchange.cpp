
#include "BitcoinExchange.hpp"

void ValidateSouceFileFormat(const std::string& filename) {
	size_t pos = filename.find(".csv");
	if (pos == std::string::npos || pos + 4 != filename.length()) {
		throw std::invalid_argument("Error: Wrong file format. Expected a .csv file.");
	}
}

void processSourceDataBaseFile(const std::string& filename, std::map<std::string, float>& sourceDataMap)
{
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open()) {
		throw std::ios_base::failure("Error: Could not open input file.");
	}

	std::string line;
	std::getline(inputFile, line); // skip the header line

	while (std::getline(inputFile, line)) {
		std::istringstream ss(line);
		std::string date, rateStr;

		if (std::getline(ss, date, ',') && std::getline(ss, rateStr))
		{
			try
			{
				float rate = std::stof(rateStr);
				sourceDataMap[date] = rate;
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
	inputFile.close();
}

bool isValidDate(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year, month, day;
	try {
		year = std::stoi(date.substr(0, 4));
		month = std::stoi(date.substr(5, 2));
		day = std::stoi(date.substr(8, 2));
	} catch (...) {
		return false;
	}

	if (year < 1 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	return true;
}

bool isValidValue(const std::string& valueStr, float& value) {
	try {
		value = std::stof(valueStr);
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

void processResultFile(const std::string& filename, const std::map<std::string, float>& exchangeRates) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // Skip header

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
		std::map<std::string, float>::const_iterator it = exchangeRates.lower_bound(date);
		if (it != exchangeRates.end() && it->first != date) {
			if (it == exchangeRates.begin()) {
				std::cerr << "Error: no earlier date available." << std::endl;
				continue;
			}
			--it;
		} else if (it == exchangeRates.end()) {
			--it;
		}

		float result = value * it->second;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
}
