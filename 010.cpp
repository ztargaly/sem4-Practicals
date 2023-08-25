/*Write a program that will read 10 integers from user and store them 
in an array. Implement array using pointers. The program will print 
the array elements in ascending and descending order*/
#include <iostream>

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortAscending(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void sortDescending(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    const int size = 10;
    int arr[size];

    std::cout << "Enter 10 integers:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Original array: ";
    printArray(arr, size);

    sortAscending(arr, size);
    std::cout << "Array in ascending order: ";
    printArray(arr, size);

    sortDescending(arr, size);
    std::cout << "Array in descending order: ";
    printArray(arr, size);

    return 0;
}
