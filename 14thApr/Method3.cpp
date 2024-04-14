// To include local headers, use double quotes instead of anglular brackets
#include "Method3.h"

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "The number with commas is: ";
    Method3 m;
    m.printDigit(num);
    cout << endl;
    return 0;
}