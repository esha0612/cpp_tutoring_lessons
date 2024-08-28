#include <iostream>

// We only discuss the outliers here

#include <iostream>

using namespace std;

int main () {

    // Bitwise operators
    // OR
    int a = 5, b = 9;
    cout << (a | b) << endl;
    // AND
    cout << (a & b) << endl;
    // XOR
    cout << (a ^ b) << endl;
    // NOT
    cout << (~a) << endl;

    // Shift operators
    // Left shift
    cout << (a << 1) << endl;
    // Right shift
    cout << (a >> 1) << endl;

    // Ternary operator
    int x = 10, y = 20;
    int z = (x != y) ? max(x, y) : 0;
    cout << z << endl;

    return 0;
}