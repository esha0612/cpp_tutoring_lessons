// Quick sort is a divide and conquer algorithm too.
// It selects a pivot element and partitions the array into two subarrays such that all elements less than the pivot are on the left and all elements greater than the pivot are on the right.
// The two subarrays are then recursively sorted.

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int low, int high) {
    // Select the rightmost element as the pivot.
    int pivot = arr[high];

    // The index of the smaller element.
    int i = low - 1;

    // Iterate through the array.
    for (int j = low; j < high; j++) {
        // If the current element is less than or equal to the pivot.
        if (arr[j] <= pivot) {
            // Increment the index of the smaller element.
            i++;

            // Swap the current element with the element at the smaller index.
            swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot element with the element at the smaller index.
    swap(arr[i + 1], arr[high]);

    // Return the index of the pivot element.
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high) {
    // If the low index is less than the high index.
    if (low < high) {
        // Partition the array.
        int pi = partition(arr, low, high);

        // Recursively sort the left subarray.
        quickSort(arr, low, pi - 1);

        // Recursively sort the right subarray.
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // The array to be sorted.
    vector<int> arr = {5, 3, 8, 4, 2, 7, 1, 10};

    // The size of the array.
    int n = arr.size();

    // Sort the array.
    quickSort(arr, 0, n - 1);

    // Print the sorted array.
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}