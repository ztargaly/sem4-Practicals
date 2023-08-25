//WAP to compute the factors of a given number.
#include <iostream>

void printFactors(int num) {
    std::cout << "Factors of " << num << " are: ";
    for (int i = 1; i <= num; ++i) {
        if (num % i == 0) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    printFactors(num);

    return 0;
}
