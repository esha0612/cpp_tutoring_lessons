// Using pointers, we cam return multiple values from a function
// This is done by passing the address of the variables to the function
// The function can then modify the values at those addresses
// Using a typecats to void*, we can return data in a type agnostic way

#include <iostream>

using namespace std;

// Example: Return an array of the first n numbers
void firstNNumbers(int n, int* numbers) {
    for (int i = 0; i < n; i++) {
        numbers[i] = i + 1;
    }
}

// Example: Return an array of the digits of a number
void digitsOfNumber(int number, int* digits, int& numDigits) {
    int temp = number;
    numDigits = 0;

    while (temp > 0) {
        temp /= 10;
        numDigits++;
    }

    temp = number;

    for (int i = numDigits - 1; i >= 0; i--) {
        digits[i] = temp % 10;
        temp /= 10;
    }
}

// Example: Create a menu to enter a type of data in console, and return it in a type agnostic way
void readData(void* data, void* type_info) {
    char type;
    cout << "Enter the type of data (i - int, d - double, c - char): ";
    cin >> type;

    *((char *)type_info) = type;

    switch (type) {
        case 'i':
            cout << "Enter an integer: ";
            cin >> *(int*)data;
            break;
        case 'd':
            cout << "Enter a double: ";
            cin >> *(double*)data;
            break;
        case 'c':
            cout << "Enter a character: ";
            cin >> *(char*)data;
            break;
        default:
            *((char *)type_info) = ' ';
    }
}

int main() {
    int n = 5;
    int* numbers = new int[n];
    firstNNumbers(n, numbers);

    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }

    cout << endl;

    delete[] numbers;

    int number = 12345;
    int* digits = new int[100];
    int numDigits;
    digitsOfNumber(number, digits, numDigits);
    delete[] digits;
    digits = new int[numDigits];
    digitsOfNumber(number, digits, numDigits);

    for (int i = 0; i < numDigits; i++) {
        cout << digits[i] << " ";
    }

    cout << endl;

    delete[] digits;

    void* data = malloc(sizeof(double));
    void* type_info = (void *)malloc(sizeof(char));
    readData(data, type_info);

    cout << "Data entered is of type: " << *((char *)type_info) << endl;

    switch (*((char *)type_info)) {
        case 'i':
            cout << "Integer: " << *(int*)data << endl;
            break;
        case 'd':
            cout << "Double: " << *(double*)data << endl;
            break;
        case 'c':
            cout << "Character: " << *(char*)data << endl;
            break;
        default:
            break;
    }

    return 0;
}