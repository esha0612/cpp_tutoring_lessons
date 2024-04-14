#include <iostream>
// #include is a preprocessor directive that tells the compiler to include the contents of the file iostream
// in this case, iostream.h is a header file that contains the declarations of the basic standard input-output library in C++
// header files contain function prototypes, data types, and other declarations that are needed to use the functions and classes defined in the library
// iostream is a standard C++ library and the definitions for that library are automatically linked by the compiler
// for nonstandard headers, the exported symbols are defined in a separate library file that needs to be linked explicitly
// including the definitions in the header file itself is also acceptable, but makes the header file larger and slower to compile

using namespace std; // this is used to avoid writing std::, by letting the compiler know that we are using the std namespace
// so if there is a function cout that it is unable to resolve, it will be searched in the std namespace

int main() {
    printf("Hello World\n");
    // std::cout << "Hello World" << std::endl;
    cout << "Hello World" << endl;
    return 0;
}