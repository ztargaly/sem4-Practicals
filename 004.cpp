//WAP to compute the sum of the first n terms of the following series 
//S =1-2+3-4+5…………….
#include <iostream>

int main() {
    int n;
    int sum = 0;

    std::cout << "Enter the value of n: ";
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 1) {
            sum += i;
        } else {
            sum -= i;
        }
    }

    std::cout << "Sum of the series: " << sum << std::endl;

    return 0;
}
