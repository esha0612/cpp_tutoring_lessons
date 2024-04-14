#include <iostream>

using namespace std;

class A {
    protected:
        int x;

    public:
        A(int x) {
            this->x = x;
        }

        void print() {
            cout << "x: " << x << endl;
        }
};

class B : public A {
    protected:
        int y;

    public:
        B() : A(0) {
            y = 0;
        }

        // : A(x) is an inline call to the constructor of the parent class
        // This is called an initializer list, and everything after the colon is called before the constructor of the child class is called
        B(int x, int y) : A(x) {
            this->y = y;
        }

        void print() {
            A::print();
            cout << "y: " << y << endl;
        }
};

int main() {
    B b(5, 6);

    b.print();

    A a = b;

    a.print();
}