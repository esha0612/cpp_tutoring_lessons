// Given an array of 0s and 1s, find the number of 0s in the array.
// The constraint is that the array may have a few 1s initially and then all 0s. There is no mixing.

#include <iostream>

using namespace std;

int approach1(int arr[], int n) {
    if (arr[0] == 0) {
        return n;
    }

    for (int i = 0; i< n; i++) {
        if (arr[i] == 0) {
            return n-i;
        }
    }

    return -1;
}

// Time complexity: O(n)

int approach2helper(int arr[], int low, int high) {
    // Base case: Either there are no 1s and the first element is 0, or you identify the first 0 (element before it is 1).
    int mid = low + (high - low)/2;
    if (arr[mid] == 0 && (arr[mid-1] == 1 || mid == 0)) {
        return mid;
    }

    if (arr[mid] == 1) {
        return approach2helper(arr, mid+1, high);
    } else {
        return approach2helper(arr, low, mid-1);
    }
}

int approach2(int arr[], int n) {
    if (arr[0] == 0) {
        return n;
    }

    return n - approach2helper(arr, 0, n-1);
}

// Time complexity: O(log n)

int main() {
    int arr[] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << approach1(arr, n) << endl;
    cout << approach2(arr, n) << endl;

    return 0;
}