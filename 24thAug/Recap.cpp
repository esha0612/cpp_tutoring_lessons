#include <iostream>
using namespace std;

/* Variables and their types:
* 1. int a = 10; // integer, range: -2^31 to 2^31 - 1
* 2. char b = 'A'; // character, range: -128 to 127
* 3. float c = 10.5; // floating point, range: -3.4e38 to 3.4e38
* 4. double d = 10.5; // floating point, range: -1.7e308 to 1.7e308
* 5. bool e = true; // boolean, range: true or false
* 6. string f = "Hello"; // string, range: any sequence of characters
*/

// Everything except string is a primitive data type. String is a class in C++.


// First, we define a short method to demonstrate overflow and underflow in C++.
/* Ranges of all primitive data types:
* 1. byte: -128 to 127
* 2. short: -32,768 to 32,767
* 3. int: -2,147,483,648 to 2,147,483,647
* 4. long: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
* 5. float: -3.4e38 to 3.4e38
* 6. double: -1.7e308 to 1.7e308
* 7. char: -128 to 127
* 8. bool: true or false
*/
// Overflow occurs when the value of a variable exceeds the maximum value that the data type can store.
// Underflow occurs when the value of a variable is less than the minimum value that the data type can store.

void overflowUnderflow() {
    // Overflow
    int a = 2147483647; // maximum value of int
    cout << "Value of a: " << a << endl;
    a++;
    cout << "Value of a after overflow: " << a << endl;

    // Underflow
    int b = -2147483648; // minimum value of int
    cout << "Value of b: " << b << endl;
    b--;
    cout << "Value of b after underflow: " << b << endl;
}

// This is an example of precision loss, which happens when non-integer values are stored in integer variables.
// In this case, the decimal part of the floating point number is truncated.
void precisionLoss() {
    float a = 10.5F;
    int b = a;
    cout << "Value of a: " << a << endl;
    cout << "Value of b after precision loss: " << b << endl;
}

// Here, we demonstrate autoboxing and autocaching in C++.
// Autoboxing is the automatic conversion of primitive data types to their corresponding wrapper classes.
// Autocaching is the automatic conversion of wrapper classes to their corresponding primitive data types.
// In this case, we are using the int and Integer classes to demonstrate autoboxing and autocaching.
void autoBoxingCaching() {
    int a = 10;
    Integer b = a; // autoboxing
    int c = b; // autocaching
    cout << "Value of a: " << a << endl;
    cout << "Value of b after autoboxing: " << b << endl;
    cout << "Value of c after autocaching: " << c << endl;
}

int main() {
    overflowUnderflow();
    precisionLoss();
    return 0;
}