// In this programme, we will delve more into abstract classes and pure virtual functions

#include <iostream>

using namespace std;

class Base {
    public:
        virtual void show() = 0; // Pure virtual function
};

class Derived : public Base {
    public:
        void show() {
            cout << "Derived class show function" << endl;
        }
};

int main() {
    // Base b; // This will give an error as we cannot create an object of an abstract class
    Derived d;
    d.show();
    return 0;
}