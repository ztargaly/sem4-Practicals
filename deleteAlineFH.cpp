#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream inputFile("data.txt");
    vector<string> lines;

    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            lines.push_back(line);
        }
        inputFile.close();
    } else {
        cerr << "Unable to open file." << endl;
        return 1;
    }

    // Deleting line at index 2 (0-based index)
    int lineToDelete = 2;
    if (lineToDelete >= 0 && lineToDelete < lines.size()) {
        lines.erase(lines.begin() + lineToDelete);
    } else {
        cerr << "Invalid line index." << endl;
        return 1;
    }

    ofstream outputFile("data.txt");
    if (outputFile.is_open()) {
        for (const string& line : lines) {
            outputFile << line << endl;
        }
        outputFile.close();
        cout << "Line deleted successfully." << endl;
    } else {
        cerr << "Unable to open file for writing." << endl;
        return 1;
    }

    return 0;
}
