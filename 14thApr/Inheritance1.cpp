#include <iostream>

using namespace std;

// Let's say we have a class A with one public method.
class A {
    public:
        void print() {
            cout << "A" << endl;
        }
};

// Now, let's say we have a class B that inherits from class A in private mode.
// This means that the public and protected members of class A become private members of class B.
class B : private A {
    public:
        void print() {
            // We can call the print method of class A from within class B.
            A::print();
            cout << "B" << endl;
        }
};

int main() {
    // We create an object of class B.
    B b;
    // We call the print method of class B.
    b.print();
    // We try to call the print method of class A.
    // b.print();
    // This will give an error because the print method of class A is private in class B.
    // This means that the print method of class A is not accessible from outside class B.
    // This is an example of inheritance in C++.
    return 0;
}