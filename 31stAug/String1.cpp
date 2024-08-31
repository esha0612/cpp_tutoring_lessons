// Now we move some string problems

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main(int argc, char* argv[]) {
    // The objective is to take the string from argv[1] and reverse it, and print it out.
    
    // First, we use C-style strings
    char* str = argv[1];
    int len = strlen(str);
    char* rev = new char[len + 1];
    for (int i = 0; i < len/2; i++) {
        rev[i] = str[len - i - 1];
        rev[len - i - 1] = str[i];
    }
    if (len % 2 == 1) {
        rev[len/2] = str[len/2];
    }
    rev[len] = '\0';
    cout << rev << endl;
    delete[] rev;

    // Now, we use C++ strings
    string str2 = argv[1];
    cout << string(str2.rbegin(), str2.rend()) << endl;

    return 0;
}