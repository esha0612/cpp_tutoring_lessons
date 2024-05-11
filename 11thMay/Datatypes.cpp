#include <iostream>
#include <string.h>

using namespace std;

// This is an example showing datatypes in C and C++, and how to display them
void primitiveDatatypes() {
    // C and C++ have the same primitive datatypes

    // char: 1 byte, -128 to 127, unsigned: 0 to 255
    char c = 'A';
    cout << "char: " << c << endl;
    printf("char: %c\n", c);

    // short: 2 bytes, -32,768 to 32,767, unsigned: 0 to 65,535
    short s = 32767;
    cout << "short: " << s << endl;
    printf("short: %d\n", s);

    // int: 4 bytes, -2,147,483,648 to 2,147,483,647, unsigned: 0 to 4,294,967,295
    int i = 2147483647;
    cout << "int: " << i << endl;
    printf("int: %d\n", i);

    // long: 4 bytes, -2,147,483,648 to 2,147,483,647, unsigned: 0 to 4,294,967,295
    long l = 2147483647;
    cout << "long: " << l << endl;
    printf("long: %ld\n", l);

    // long long: 8 bytes, -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807, unsigned: 0 to 18,446,744,073,709,551,615
    long long ll = 9223372036854775807;
    cout << "long long: " << ll << endl;
    printf("long long: %lld\n", ll);

    // float: 4 bytes, 7 decimal digits
    float f = 3.14;
    cout << "float: " << f << endl;
    printf("float: %f\n", f);

    // double: 8 bytes, 15 decimal digits
    double d = 3.14159265358979323846;
    cout << "double: " << d << endl;
    printf("double: %lf\n", d);

    // long double: 10 bytes, 19 decimal digits
    long double ld = 3.14159265358979323846;
    cout << "long double: " << ld << endl;
    printf("long double: %Lf\n", ld);

    // bool: 1 byte, true or false
    bool b = true;
    cout << "bool: " << b << endl;

    // void: no value
    // void v = NULL; // This will give an error

    // Displaying the size of each datatype
    cout << "Size of char: " << sizeof(char) << " bytes" << endl;
    cout << "Size of short: " << sizeof(short) << " bytes" << endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of long: " << sizeof(long) << " bytes" << endl;
    cout << "Size of long long: " << sizeof(long long) << " bytes" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of long double: " << sizeof(long double) << " bytes" << endl;
    cout << "Size of bool: " << sizeof(bool) << " bytes" << endl;
    // cout << "Size of void: " << sizeof(void) << " bytes" << endl; // This will give an error
}

// User-defined datatypes:

// array: a collection of elements of the same datatype
void arrayDatatype() {
    // C++ style:
    int arr[5] = {1, 2, 3, 4, 5};
    // the above is equivalent to: int* arr = new int[5]; arr[0] = 1; arr[1] = 2; arr[2] = 3; arr[3] = 4; arr[4] = 5;
    cout << "Array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // C style:
    // int* arr2 = (int*)malloc(5 * sizeof(int)); -> the difference between malloc and calloc is that malloc does not initialize the memory, while calloc initializes it to 0
    int* arr2 = (int *)calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr2[i] = i + 1;
    }
    cout << "Array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
}

// enum: a user-defined datatype that consists of a set of named integer constants
void enumDatatype() {
    enum Color {RED, GREEN, BLUE};
    Color c = RED;
    cout << "Enum: " << c << endl;
}

// union: a user-defined datatype that allows storing different datatypes in the same memory location
void unionDatatype() {
    union Data {
        int i;
        float f;
        char str[20];
    };
    Data data;
    data.i = 10;
    cout << "Union: " << data.i << endl;
    data.f = 3.14;
    cout << "Union: " << data.f << endl;
    strcpy(data.str, "Hello, World!");
    cout << "Union: " << data.str << endl;
}

// struct: a user-defined datatype that allows storing different datatypes in the same memory location
// difference between struct and union is that struct allocates memory for all its members, while union allocates memory for the largest member
// struct is used when you want to store multiple values in a single variable, while union is used when you want to store only one value at a time
// struct is like a class but with public access by default
void structDatatype() {
    struct Person {
        char name[50];
        int age;
        float salary;
    };
    Person p;
    strcpy(p.name, "John Doe");
    p.age = 30;
    p.salary = 50000.0;
    cout << "Struct: " << p.name << " " << p.age << " " << p.salary << endl;
}

// typedef: a keyword used to create an alias for a datatype
// an example:
typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;
// the above is an anonymous struct, which is used when you don't want to use the struct name
void typedefDatatype() {
    Employee e;
    strcpy(e.name, "Jane Doe");
    e.age = 25;
    e.salary = 40000.0;
    cout << "Typedef: " << e.name << " " << e.age << " " << e.salary << endl;
}

int main() {
    primitiveDatatypes();
    arrayDatatype();
    enumDatatype();
    unionDatatype();
    structDatatype();
    typedefDatatype();
    return 0;
}