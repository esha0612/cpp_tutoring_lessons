// Pass by value and pass by reference
// In C++, function arguments can be passed by value or by reference.
// When an argument is passed by value, a copy of the argument is made and passed to the function.
// This means that changes made to the argument inside the function do not affect the original value.
// When an argument is passed by reference, the memory address of the argument is passed to the function.
// This allows the function to directly modify the original value.

#include <iostream>

using namespace std;

// Pass by value
void incrementByValue(int num) {
    num++;
}

// Pass by reference
void incrementByReference(int& num) {
    num++;
}

// Pass by pointer (also a form of pass by reference)
void incrementByPointer(int* num) {
    (*num)++;
}

int main() {
    int num = 42;

    // Pass by value
    cout << "Before incrementByValue: " << num << endl;
    incrementByValue(num);
    cout << "After incrementByValue: " << num << endl;

    // Pass by reference
    cout << "Before incrementByReference: " << num << endl;
    incrementByReference(num);
    cout << "After incrementByReference: " << num << endl;

    // Pass by pointer
    cout << "Before incrementByPointer: " << num << endl;
    incrementByPointer(&num);
    cout << "After incrementByPointer: " << num << endl;

    return 0;
}