// There are many forms of strings in C++.
// 1. C-style strings (char arrays, null-terminated)
// 2. C++ strings (std::string)
// 3. C++ string literals (const char*)
// 4. C++ string view (std::string_view)
// 5. C++ string stream (std::stringstream)
// 6. C++ string buffer (std::stringbuf)
// 7. Specialized string classes (std::basic_string, std::wstring, std::u16string, std::u32string, LPCTSTR, LPTSTR, BSTR, CString, etc.)

#include <iostream>
#include <string>

// For college, mostly remembering the first 3 is enough.

using namespace std;

int main()
{
    // C-style strings
    char str[] = "Hello"; // This will become a null-terminated string (if you declare and initialize it together)
    cout << str << endl;

    // C++ strings
    string str2 = "World";
    cout << str2 << endl;

    // C++ string literals
    const char* str3 = "!";
    cout << str3 << endl;

    return 0;
}