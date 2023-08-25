//Write a macro that swaps two numbers. WAP to use it.
#include <iostream>

#define SWAP(a, b) do { \
    auto temp = a; \
    a = b; \
    b = temp; \
} while(0)

int main() {
    int num1, num2;

    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    std::cout << "Before swapping: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    SWAP(num1, num2);

    std::cout << "After swapping: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    return 0;
}
