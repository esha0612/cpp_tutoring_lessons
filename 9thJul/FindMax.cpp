// In this problem, we will use divide and conquer to find the maximum element in an array.
// The FindMax function takes an array and the low and high indices as input and returns the maximum element in the array.

#include <iostream>

using namespace std;

// So, in divide and conquer problems, these are the steps we follow:
// 1. Identify the base case when the problem can be solved directly.
// 2. Divide the problem into smaller subproblems which can be recursively divided into smaller subproblems, all the way down to the base case.
// 3. Combine the solutions of the subproblems to solve the original problem, with additional processing if needed.
// 1. and 2. are the divide part, and 3. is the conquer part.

// The base case, where we can solve in O(1) time, is when the array has 1 or 2 elements.
// If the array has 1 element, the maximum element is the only element in the array.
// If the array has 2 elements, the maximum element is the larger of the two elements.
// So our divide step is to split the array into two halves and recursively find the maximum element in each half.
// The conquer step is to compare the maximum elements of the two halves and return the larger of the two.

int FindMax(int arr[], int low, int high) {
    // Base case: If the array has only one element, return that element
    if (low == high) {
        return arr[low];
    }

    // Base case: If the array has two elements, return the larger of the two
    if (low + 1 == high) {
        return max(arr[low], arr[high]);
    }

    // Divide the array into two halves
    int mid = (low + high) / 2;

    // Recursively find the maximum element in each half
    int max1 = FindMax(arr, low, mid);
    int max2 = FindMax(arr, mid + 1, high);

    // Combine the solutions by returning the larger of the two maximum elements
    return max(max1, max2);
}

int main() {
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The maximum element in the array is: " << FindMax(arr, 0, n - 1) << endl;
    return 0;
}