#include<iostream>

using namespace std;

// This is an example showing typecasting in C and C++

// Some examples of implicit typecasting
void implicitTypecasting() {
    // int to float
    int i = 10;
    float f = i;
    cout << "int to float: " << f << endl;

    // char to int
    char c = 'A';
    i = c;
    cout << "char to int: " << i << endl;

    // char to float
    f = c;
    cout << "char to float: " << f << endl;

    // int to double
    double d = i;
    cout << "int to double: " << d << endl;

    // char to double
    d = c;
    cout << "char to double: " << d << endl;

    // float to double
    d = f;
    cout << "float to double: " << d << endl;

    // long to long long
    long l = 1000000000;
    long long ll = l;
    cout << "long to long long: " << ll << endl;
}

// Some examples of explicit typecasting
void explicitTypecasting() {
    // float to int
    float f = 3.14;
    int i = (int)f;
    cout << "float to int: " << i << endl;

    // double to int
    double d = 3.14;
    i = (int)d;
    cout << "double to int: " << i << endl;

    // double to float
    f = (float)d;
    cout << "double to float: " << f << endl;

    // int to char
    i = 65;
    char c = (char)i;
    cout << "int to char: " << c << endl;

    // float to char
    f = 65.5;
    c = (char)f;
    cout << "float to char: " << c << endl;

    // double to char
    d = 65.5;
    c = (char)d;
    cout << "double to char: " << c << endl;

    // int to char
    i = 65;
    c = (char)i;
    cout << "int to char: " << c << endl;

    // int to float
    i = 65;
    f = (float)i;
    cout << "int to float: " << f << endl;

    // int to double
    d = (double)i;
    cout << "int to double: " << d << endl;

    // long to long long
    long l = 1000000000;
    long long ll = (long long)l;
    cout << "long to long long: " << ll << endl;
}

// Some examples of typecasting between user-defined datatypes
void userDefinedTypecasting() {
    // array to pointer
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr;
    cout << "Array to pointer: ";
    for (int i = 0; i < 5; i++) {
        cout << ptr[i] << " ";
    }
    cout << endl;

    // pointer to array
    int* ptr2 = new int[5];
    for (int i = 0; i < 5; i++) {
        ptr2[i] = i + 1;
    }
    int arr2[5];
    for (int i = 0; i < 5; i++) {
        arr2[i] = ptr2[i];
    }
    cout << "Pointer to array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // pointer to function
    void (*funcPtr)() = NULL;
    cout << "Pointer to function: " << funcPtr << endl;

    // function to pointer
    void func() {
        cout << "Function" << endl;
    }
    void (*funcPtr2)() = func;

    // class to pointer
    class A {
    public:
        void print() {
            cout << "Class" << endl;
        }
    };
    A a;
    void (A::*classPtr)() = &A::print;
    (a.*classPtr)();

    // pointer to class
    A* aPtr = &a;
    (aPtr->*classPtr)();
    
    // class to function
    void (A::*classPtr2)() = &A::print;
    (a.*classPtr2)();

    // function to class
    void (*funcPtr3)() = func;
    funcPtr3();

    // class to int
    int* intPtr = (int*)&a;
    cout << "Class to int: " << *intPtr << endl;

    // pointer to pointer (say, void* to class*)
    void* voidPtr = &a;
    A* aPtr2 = (A*)voidPtr;
    aPtr2->print();

    // pointer to pointer (say, int* to char*)
    int i = 65;
    int* iPtr = &i;
    char* cPtr = (char*)iPtr;
    cout << "Pointer to pointer: " << *cPtr << endl;   

    // pointer to reference
    int j = 10;
    int* jPtr = &j;
    int& jRef = *jPtr;
    cout << "Pointer to reference: " << jRef << endl;

    // reference to pointer
    int k = 20;
    int& kRef = k;
    int* kPtr = &kRef;
    cout << "Reference to pointer: " << *kPtr << endl;

    // pointer to void pointer
    void* voidPtr2 = jPtr;
    cout << "Pointer to void pointer: " << *(int*)voidPtr2 << endl;

    // void pointer to pointer
    int* jPtr2 = (int*)voidPtr2;
    cout << "Void pointer to pointer: " << *jPtr2 << endl;
}

int main() {
    implicitTypecasting();
    explicitTypecasting();
    userDefinedTypecasting();
    return 0;
}