// We will try different ways to calculate the exponential of a number (x^n).
// Assume that n is a natural number.

#include <iostream>

using namespace std;

// We will agree to not use any built-in functions to calculate the exponential.

int approach1(int x, unsigned int n) {
    if (n == 1 || x == 0 || x == 1) {
        return x;
    }
    return x * approach1(x, n-1);
}
// The above approach is a simple recursive approach. It is not efficient because it calculates the exponential in O(n) time.
int approach2(int x, unsigned int n) {
    int result = x;
    for (int i = 2; i <= n; i++){
        result *= x;
    }
    return result;
}
// The above approach is a simple recursive approach. It is not efficient because it calculates the exponential in O(n) time.

// Let's try a divide and conquer approach.
int approach3(int x, unsigned int n) {
    if (n == 1 || x == 0 || x == 1) {
        return x;
    }
    else if (n % 2 == 0) {
        return approach3(x, n/2) * approach3(x, n/2);
    }
    else {
        return x * approach3(x, n/2) * approach3(x, n/2);
    }
}
// This is still not efficient because it calculates the exponential in O(n) time, because even though we are
// dividing the problem into smaller subproblems, we are calculating the same subproblem twice.

// Let's try a more efficient approach.
int approach4(int x, unsigned int n) {
    if (n == 1 || x == 0 || x == 1) {
        return x;
    }
    int result = approach4(x, n/2);
    if (n % 2 == 0) {
        return result * result;
    }
    else {
        return x * result * result;
    }
}
// By storing it and reusing it, we can calculate the exponential in O(log n) time.
// This is called memoization.