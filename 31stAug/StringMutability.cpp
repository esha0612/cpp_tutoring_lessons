// In Java, Strings are immutable. This means that once a String object is created, it cannot be changed.
// Any changes in the String object will result in a new String object, or any memory changes will result in a new String object.
// In C++, strings are mutable. This means that you can change the contents of a string object.
// This holds true for most C-style strings and C++ strings. However, there are some exceptions.
// For example, std::string_view, which is a non-owning reference to a string, is immutable.
// Also, LPCTSTR and LPTSTR are immutable, as they are pointers to const characters.
// C++ string literals, aka const char*, are also immutable after initialization.
// A good thumb rule is that if a string is a pointer to const characters, it is immutable.

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Demonstrating string mutability in char arrays
    char str[] = "Hello";
    cout << str << endl;
    str[0] = 'Y';
    cout << str << endl;

    // Demonstrating string mutability in C++ strings
    string str2 = "World";
    cout << str2 << endl;
    str2[0] = 'Y';
    cout << str2 << endl;

    // Demonstrating string mutability in C++ string literals
    const char* str3 = "!";
    cout << str3 << endl;
    // str3[0] = 'Y'; // This will give an error, because of const - the L-value is read-only and not modifiable
    // cout << str3 << endl;

    return 0;
}