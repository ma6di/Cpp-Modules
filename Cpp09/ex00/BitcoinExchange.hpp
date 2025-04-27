
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

//heap years
//names
//all checks

void processSourceDataBaseFile(const std::string& filename, std::map<std::string, float>& sourceDataMap);
void processResultFile(const std::string& filename, const std::map<std::string, float>& exchangeRates);

void ValidateSouceFileFormat(const std::string& filename);
