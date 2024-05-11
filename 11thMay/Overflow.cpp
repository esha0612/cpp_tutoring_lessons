#include <iostream>

using namespace std;

// This is an example showing overflow of datatypes in C and C++
int main() {
    // overflow in short, range: -32,768 to 32,767, size: 2 bytes
    short s = 32767;
    cout << "short: " << s << endl;
    cout << "short + 1: " << s + 1 << endl;
    cout << "++short: " << ++s << endl;
    cout << "++short: " << ++s << endl;
    s = -32768;
    cout << "short: " << s << endl;
    cout << "--short: " << --s << endl;

    // overflow in char, range: -128 to 127, size: 1 byte
    char c = 122;
    // notice how you can do implicit conversion from int to char
    cout << "char: " << c << endl;
    cout << "char + 1: " << c + 1 << endl;
    c = 'Z';
    cout << "char + 'a' - 40: " << c + 'a' - 40 << endl;
    c = 45;
    cout << "char + 'a': " << c + 'a' << endl;
    // What happens when you add 1 to 127?
    c = 127;
    cout << "char: " << c << endl;
    cout << "char + 1: " << c + 1 << endl;
    cout << "++char: " << ++c << endl;
    cout << "++char: " << ++c << endl;
    cout << "char + 1: " << c + 1 << endl;

    return 0;
}