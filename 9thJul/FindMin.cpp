// Same as FindMax.cpp but with the comparison operator reversed.

#include <iostream>

using namespace std;
int FindMin(int arr[], int low, int high) {
    // Base case: If the array has only one element, return that element
    if (low == high) {
        return arr[low];
    }

    // Base case: If the array has two elements, return the larger of the two
    if (low + 1 == high) {
        return min(arr[low], arr[high]);
    }

    // Divide the array into two halves
    int mid = (low + high) / 2;

    // Recursively find the maximum element in each half
    int max1 = FindMin(arr, low, mid);
    int max2 = FindMin(arr, mid + 1, high);

    // Combine the solutions by returning the larger of the two maximum elements
    return min(max1, max2);
}

int main() {
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The minimum element in the array is: " << FindMin(arr, 0, n - 1) << endl;
    return 0;
}