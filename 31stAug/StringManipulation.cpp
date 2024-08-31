// Here, we discuss some common string manipulation functions in C++.

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    // Find the length of a string
    string str = "Hello, World!";
    cout << str.length() << endl;
    cout << str.size() << endl;
    cout << sizeof(str)/sizeof(char) << endl;

    // Accessing characters in a string
    cout << str[0] << endl;
    cout << str.at(0) << endl;

    // Modifying characters in a string
    str[0] = 'Y';
    cout << str << endl;
    str.at(0) = 'Z';
    cout << str << endl;

    // Appending to a string
    str.append("!!!");
    cout << str << endl;

    // Inserting into a string
    str.insert(5, " there");
    cout << str << endl;

    // Erasing from a string
    str.erase(5, 6);
    cout << str << endl;

    // Clearing a string
    str.clear();
    cout << str << endl;

    // We try to do the same for C-style strings
    char str2[] = "Hello, World!";

    // Find the length of a string
    cout << strlen(str2) << endl;
    cout << sizeof(str2)/sizeof(char) << endl;

    // Accessing characters in a string
    cout << str2[0] << endl;

    // Modifying characters in a string
    str2[0] = 'Y';
    cout << str2 << endl;

    // Appending to a string
    strcat(str2, "!!!");
    cout << str2 << endl;

    // Inserting into a string
    strncat(str2, " there", 7);
    cout << str2 << endl;

    // Erasing from a string
    str2[5] = '\0';
    cout << str2 << endl;

    // Clearing a string
    memset(str2, '\0', sizeof(str2));
    cout << str2 << endl;

    return 0;
}