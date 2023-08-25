/*Create a structure Student containing fields for Roll No., Name, 
Class, Year and Total Marks. Create 10 students and store them in a 
file.*/
#include <iostream>
#include <fstream>
#include <string>

struct Student {
    int rollNo;
    std::string name;
    std::string className;
    int year;
    double totalMarks;
};

int main() {
    const int numStudents = 10;

    Student students[numStudents];

    // Input student data
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Enter details for student " << i + 1 << ":" << std::endl;
        students[i].rollNo = i + 1;

        std::cout << "Name: ";
        std::cin.ignore();  // Clear newline character from previous input
        std::getline(std::cin, students[i].name);

        std::cout << "Class: ";
        std::getline(std::cin, students[i].className);

        std::cout << "Year: ";
        std::cin >> students[i].year;

        std::cout << "Total Marks: ";
        std::cin >> students[i].totalMarks;
    }

    // Store student data in a file
    std::ofstream outputFile("students.txt");

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    for (int i = 0; i < numStudents; ++i) {
        outputFile << "Roll No: " << students[i].rollNo << std::endl;
        outputFile << "Name: " << students[i].name << std::endl;
        outputFile << "Class: " << students[i].className << std::endl;
        outputFile << "Year: " << students[i].year << std::endl;
        outputFile << "Total Marks: " << students[i].totalMarks << std::endl;
        outputFile << std::endl;
    }

    outputFile.close();

    std::cout << "Student records have been written to students.txt" << std::endl;

    return 0;
}
