/*Create a class Box containing length, breath and height. Include 
following methods in it: 
a) Calculate surface Area 
b) Calculate Volume 
c) Increment, Overload ++ operator (both prefix & postfix) 
d) Decrement, Overload -- operator (both prefix & postfix) 
e) Overload operator == (to check equality of two boxes), as a friend 
function 
f) Overload Assignment operator g) Check if it is a Cube or cuboid*/
#include <iostream>

class Box {
private:
    double length;
    double breadth;
    double height;

public:
    // Constructor
    Box(double len, double br, double h) : length(len), breadth(br), height(h) {}

    // Methods
    double calculateSurfaceArea() const {
        return 2 * (length * breadth + breadth * height + height * length);
    }

    double calculateVolume() const {
        return length * breadth * height;
    }

    void increment() {
        ++length;
        ++breadth;
        ++height;
    }

    void decrement() {
        --length;
        --breadth;
        --height;
    }

    // Overload ++ operator (prefix)
    Box& operator++() {
        increment();
        return *this;
    }

    // Overload ++ operator (postfix)
    Box operator++(int) {
        Box temp(*this);
        increment();
        return temp;
    }

    // Overload -- operator (prefix)
    Box& operator--() {
        decrement();
        return *this;
    }

    // Overload -- operator (postfix)
    Box operator--(int) {
        Box temp(*this);
        decrement();
        return temp;
    }

    // Friend function to overload == operator
    friend bool operator==(const Box& lhs, const Box& rhs) {
        return (lhs.length == rhs.length && lhs.breadth == rhs.breadth && lhs.height == rhs.height);
    }

    // Overload assignment operator
    Box& operator=(const Box& other) {
        if (this != &other) {
            length = other.length;
            breadth = other.breadth;
            height = other.height;
        }
        return *this;
    }

    // Check if it's a Cube or Cuboid
    std::string getType() const {
        if (length == breadth && breadth == height) {
            return "Cube";
        } else {
            return "Cuboid";
        }
    }
};

int main() {
    Box box1(3.0, 4.0, 5.0);
    Box box2(3.0, 3.0, 3.0);
    
    std::cout << "Surface Area of box1: " << box1.calculateSurfaceArea() << std::endl;
    std::cout << "Volume of box1: " << box1.calculateVolume() << std::endl;

    Box box3 = box1;
    box3.increment();
    std::cout << "box3: " << box3.calculateVolume() << std::endl;

    Box box4 = ++box1;
    std::cout << "box4: " << box4.calculateVolume() << std::endl;

    Box box5 = box1++;
    std::cout << "box5: " << box5.calculateVolume() << std::endl;

    Box box6 = box1--;
    std::cout << "box6: " << box6.calculateVolume() << std::endl;

    Box box7 = --box1;
    std::cout << "box7: " << box7.calculateVolume() << std::endl;

    if (box1 == box2) {
        std::cout << "box1 and box2 are equal." << std::endl;
    } else {
        std::cout << "box1 and box2 are not equal." << std::endl;
    }

    std::cout << "Type of box1: " << box1.getType() << std::endl;
    std::cout << "Type of box2: " << box2.getType() << std::endl;

    return 0;
}
