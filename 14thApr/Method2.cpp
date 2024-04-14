// Another point about methods in C++ is that they can be called before definition, or even declaration.

#include <iostream>

using namespace std;

int fibonacci(int n);

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "The " << num << "th Fibonacci number is: " << fibonacci(num) << endl;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}