// This is an introduction to pointers in C++.
// A pointer is a variable that stores the memory address of another variable.
// Pointers are used to work with memory addresses and manipulate data at a low level.
// They are an essential feature of C++ and are commonly used in dynamic memory allocation and data structures.
// C++ is therefore not a memory-safe language, and using pointers incorrectly can lead to memory leaks and other bugs.
// Memory "ownership" is a key concept in C++ that determines who is responsible for managing the memory associated with a pointer.
// In general, memory allocated to a certain process should be freed by the same process.

#include <iostream>

using namespace std;

int main() {
    // Declare a variable num of type int and assign it the value 42.
    int num = 42;
    // Declare a pointer ptr of type int* and assign it the memory address of num.
    int* ptr = &num;

    // Print the value of num.
    cout << "Value of num: " << num << endl;
    // Print the memory address of num.
    cout << "Memory address of num: " << &num << endl;
    // Print the value of ptr.
    cout << "Value of ptr: " << ptr << endl;
    // Print the memory address of ptr.
    cout << "Memory address of ptr: " << &ptr << endl;
    // Print the value at the memory address stored in ptr.
    cout << "Value at ptr: " << *ptr << endl;

    // Change the value of num through ptr.
    *ptr = 100;
    // Print the new value of num.
    cout << "New value of num: " << num << endl;

    return 0;
}