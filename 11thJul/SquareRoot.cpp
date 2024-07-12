// Calculate the square root of a natural number n.
// The square root of n is the number x such that x*x = n.
// If the square root is not an integer itself, return the floor of the square root.
// Floor of a number is the greatest integer less than or equal to the number.

#include <iostream>

using namespace std;

int approach1(int n) {
    if (n==1) {
        return n;
    }
    int i = 1;
    while (i*i <= n) {
        i++;
    }
    return i-1;
}

// Time complexity: O(sqrt(n))

int main() {
    int n = 62;

    cout << approach1(n) << endl;

    return 0;
}