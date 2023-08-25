/*
Write a function that checks whether a given string is Palindrome or 
not. Use this function to find whether the string entered by user is 
Palindrome or not.*/
#include <iostream>
#include <string>
#include <cctype>

bool isPalindrome(const std::string &str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (std::tolower(str[left]) != std::tolower(str[right])) {
            return false;
        }
        ++left;
        --right;
    }

    return true;
}

int main() {
    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "The entered string is a palindrome." << std::endl;
    } else {
        std::cout << "The entered string is not a palindrome." << std::endl;
    }

    return 0;
}
