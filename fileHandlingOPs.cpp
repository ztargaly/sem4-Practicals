#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    // Read existing content from the file
    ifstream inputFile("data.txt");
    vector<string> lines;

    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            lines.push_back(line);
        }
        inputFile.close();
    } else {
        cerr << "Unable to open file for reading." << endl;
        return 1;
    }

    // Insert new data
    ofstream outputFile("data.txt", ios::app);
    if (outputFile.is_open()) {
        string newLine = "New Line Inserted!";
        outputFile << newLine << endl;
        outputFile.close();
        cout << "Data inserted successfully." << endl;
    } else {
        cerr << "Unable to open file for writing." << endl;
        return 1;
    }

    // Delete a specific line (line 2 in this case)
    int lineToDelete = 1;
    if (lineToDelete >= 0 && lineToDelete < lines.size()) {
        lines.erase(lines.begin() + lineToDelete);
    } else {
        cerr << "Invalid line index for deletion." << endl;
        return 1;
    }

    // Update content of line 1
    int lineToUpdate = 0;
    if (lineToUpdate >= 0 && lineToUpdate < lines.size()) {
        lines[lineToUpdate] = "Updated Line!";
    } else {
        cerr << "Invalid line index for update." << endl;
        return 1;
    }

    // Write the modified content back to the file
    ofstream modifiedFile("data.txt");
    if (modifiedFile.is_open()) {
        for (const string& line : lines) {
            modifiedFile << line << endl;
        }
        modifiedFile.close();
        cout << "File modifications saved successfully." << endl;
    } else {
        cerr << "Unable to open file for writing modifications." << endl;
        return 1;
    }

    return 0;
}
