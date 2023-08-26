#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outputFile("data.txt", ios::app); // Open in append mode

    if (outputFile.is_open()) {
        string newLine = "New Line Inserted!";
        outputFile << newLine << endl;
        outputFile.close();
        cout << "Data inserted successfully." << endl;
    } else {
        cerr << "Unable to open file for writing." << endl;
        return 1;
    }

    return 0;
}
