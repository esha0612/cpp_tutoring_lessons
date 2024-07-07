// Binary Search is a divide and conquer algorithm that finds the position of a target value within a sorted array.
// We discard half of the elements in the array at each step based on the comparison of the target value with the middle element.

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, int target) {
    // Initialize the low and high indices.
    int low = 0;
    int high = arr.size() - 1;

    // Repeat until the low index is less than or equal to the high index.
    while (low <= high) {
        // Find the middle index of the array.
        int mid = low + (high - low) / 2;

        // If the target value is equal to the middle element.
        if (arr[mid] == target) {
            // Return the index of the middle element.
            return mid;
        }

        // If the target value is less than the middle element.
        if (target < arr[mid]) {
            // Discard the right half of the array.
            high = mid - 1;
        } else {
            // Discard the left half of the array.
            low = mid + 1;
        }
    }

    // Return -1 if the target value is not found in the array.
    return -1;
}

int main() {
    // The sorted array to search in.
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // The target value to search for.
    int target = 5;

    // Find the position of the target value in the array.
    int index = binarySearch(arr, target);

    // Print the index of the target value.
    if (index != -1) {
        cout << "The target value is at index " << index << endl;
    } else {
        cout << "The target value is not in the array" << endl;
    }

    return 0;
}