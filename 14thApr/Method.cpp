// In this program, we will learn how to write and call a method in C++.
// A method is a block of code that performs a specific task. It is similar to a function in C.

#include <iostream>

using namespace std;

// defining a method to take in a number and print the digits of the number with commas in between
// this is a global method, which means it can be called from anywhere in the program
// C++ does not need methods to be defined in a class
void printDigit(int num) {
    if (num < 0) {
        cout << "- ";
        num = -num;
    }
    if (num < 10) {
        cout << num;
    } else {
        printDigit(num / 10);
        cout << "," << num % 10;
    }
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "The number with commas is: ";
    printDigit(num);
    cout << endl;
    return 0;
}