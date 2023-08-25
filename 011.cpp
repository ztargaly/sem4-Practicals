/* Write a function that reverses the elements of an array in place. The 
function must accept only one pointer value and return void.*/
#include <iostream>

void reverseArray(int* arr, int size) {
    int start = 0;
    int end = size - 1;
    
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        ++start;
        --end;
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int size = 5;
    int arr[size];

    std::cout << "Enter " << size << " integers:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Original array: ";
    printArray(arr, size);

    reverseArray(arr, size);

    std::cout << "Reversed array: ";
    printArray(arr, size);

    return 0;
}
