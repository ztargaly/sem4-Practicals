/*Create the Person class. Create some objects of this class (by taking 
information from the user). Inherit the class Person to create two
classes Teacher and Student class. Maintain the respective 
information in the classes and create, display and delete objects of 
these two classes (Use Runtime Polymorphism)*/
#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& n, int a) : name(n), age(a) {}

    virtual void display() {
        std::cout << "Name: " << name << ", Age: " << age;
    }

    virtual ~Person() {
        std::cout << "Person object destroyed." << std::endl;
    }
};

class Teacher : public Person {
private:
    std::string subject;

public:
    Teacher(const std::string& n, int a, const std::string& sub) : Person(n, a), subject(sub) {}

    void display() override {
        std::cout << "Teacher - ";
        Person::display();
        std::cout << ", Subject: " << subject << std::endl;
    }

    ~Teacher() override {
        std::cout << "Teacher object destroyed." << std::endl;
    }
};

class Student : public Person {
private:
    int rollNumber;

public:
    Student(const std::string& n, int a, int roll) : Person(n, a), rollNumber(roll) {}

    void display() override {
        std::cout << "Student - ";
        Person::display();
        std::cout << ", Roll Number: " << rollNumber << std::endl;
    }

    ~Student() override {
        std::cout << "Student object destroyed." << std::endl;
    }
};

int main() {
    Person* people[3];

    for (int i = 0; i < 3; ++i) {
        std::string name;
        int age;

        std::cout << "Enter name: ";
        std::getline(std::cin, name);

        std::cout << "Enter age: ";
        std::cin >> age;
        std::cin.ignore(); // Clear newline character

        if (i % 2 == 0) {
            std::string subject;
            std::cout << "Enter subject: ";
            std::getline(std::cin, subject);
            people[i] = new Teacher(name, age, subject);
        } else {
            int rollNumber;
            std::cout << "Enter roll number: ";
            std::cin >> rollNumber;
            std::cin.ignore(); // Clear newline character
            people[i] = new Student(name, age, rollNumber);
        }
    }

    std::cout << "Displaying created objects:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        people[i]->display();
    }

    for (int i = 0; i < 3; ++i) {
        delete people[i];
    }

    return 0;
}
