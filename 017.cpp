/* WAP to calculate Factorial of a number (i)using recursion, (ii) using 
iteration*/
#include <iostream>

// Using recursion
int factorialRecursion(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorialRecursion(n - 1);
}

// Using iteration
int factorialIteration(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int num;

    std::cout << "Enter a positive integer: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
    } else {
        int factRecursion = factorialRecursion(num);
        int factIteration = factorialIteration(num);

        std::cout << "Factorial using recursion: " << factRecursion << std::endl;
        std::cout << "Factorial using iteration: " << factIteration << std::endl;
    }

    return 0;
}
