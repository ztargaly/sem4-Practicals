//WAP to compute the sum of the first n terms of the following series 
//S = 1+1/2+1/3+1/4+……
#include <iostream>

int main() {
    int n;
    double sum = 0.0;

    std::cout << "Enter the value of n: ";
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        sum += 1.0 / i;
    }

    std::cout << "Sum of the series: " << sum << std::endl;

    return 0;
}
