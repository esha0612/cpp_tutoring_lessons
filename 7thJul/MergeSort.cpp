// Merge sort is a divide and conquer algorithm that divides the array into two halves, sorts the two halves, and then merges the two sorted halves.

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    // Create two temporary arrays to store the two halves of the array.
    vector<int> left(arr.begin() + low, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + high + 1);

    // Initialize the indices for the two halves.
    int i = 0, j = 0, k = low;

    // Merge the two halves back into the original array.
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of the left half, if any.
    while (i < left.size()) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of the right half, if any.
    while (j < right.size()) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        // Find the middle index of the array.
        int mid = low + (high - low) / 2;

        // Recursively divide the array into two halves.
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge the two halves.
        merge(arr, low, mid, high);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}