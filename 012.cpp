#include <iostream>
#include <fstream>
#include <cctype>

int main() {
    std::string inputFileName = "input.txt";     // Change this to your input file name
    std::string outputFileName = "output.txt";   // Change this to your output file name

    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    char c;
    while (inputFile.get(c)) {
        if (!std::isspace(c)) {
            outputFile.put(c);
        }
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Whitespace removed and written to " << outputFileName << std::endl;

    return 0;
}
