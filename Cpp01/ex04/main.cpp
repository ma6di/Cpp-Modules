#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(const std::string& line, const std::string& s1, const std::string& s2) {

    if (s1.empty()) {
        throw std::invalid_argument("s1 cannot be an empty string.");
    }

    std::string result; // String to hold the final modified string
    size_t pos = 0;     // Position of the substring found in the string
    size_t start = 0;   // The start position for the next search

    // Loop through the entire string and replace s1 with s2
    while ((pos = line.find(s1, start)) != std::string::npos) {
        result += line.substr(start, pos - start); // Append part before s1
        result += s2;                             // Replace s1 with s2
        start = pos + s1.length();                // Move past the current occurrence of s1
    }
    
    // Append the remainder of the string after the last occurrence of s1
    result += line.substr(start);
    return result;
}

// Function to process the file and replace occurrences of s1 with s2
void processFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
    std::ifstream inputFile(filename.c_str()); // Use .c_str() to convert std::string to const char*
    if (!inputFile.is_open()) { 
        throw std::ios_base::failure("Error: Could not open input file.");
    }

    std::ofstream outputFile((filename + ".replace").c_str()); // Use .c_str() for the concatenated string
    if (!outputFile.is_open()) {
        throw std::ios_base::failure("Error: Could not create output file.");
    }

    std::string line;

    // Read each line from the input file and process it
    while (std::getline(inputFile, line)) {
        outputFile << replaceAll(line, s1, s2) << '\n';  // Write the modified line to the output file after replacing occurrences of s1 with s2
    }

    inputFile.close();
    outputFile.close();
}

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments are provided (filename, s1, s2)
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    try {
        std::string filename = argv[1];
        std::string s1 = argv[2];
        std::string s2 = argv[3];

        // Call the function to process the file and replace occurrences of s1 with s2
        processFile(filename, s1, s2);

        // Output a success message after processing the file
        std::cout << "File processed successfully. Output: " << filename << ".replace" << std::endl;
    } catch (const std::exception& e) { // Catch any exceptions thrown during the file processing
        std::cerr << e.what() << std::endl; // Output the error message
        return 1;
    }

    return 0;
}
