// WAP to print the sum and product of digits of an integer
#include <iostream>

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    int originalNum = num;
    int sum = 0;
    int product = 1;

    while (num != 0) {
        int digit = num % 10;
        sum += digit;
        product *= digit;
        num /= 10;
    }

    std::cout << "Number: " << originalNum << std::endl;
    std::cout << "Sum of digits: " << sum << std::endl;
    std::cout << "Product of digits: " << product << std::endl;

    return 0;
}
