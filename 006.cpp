/*Write a function to find whether a given no. is prime or not. Use the 
same to generate the prime numbers less than 100.*/
#include <iostream>
#include <cmath>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    if (num <= 3) {
        return true;
    }

    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    std::cout << "Prime numbers less than 100:" << std::endl;

    for (int i = 2; i < 100; ++i) {
        if (isPrime(i)) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
