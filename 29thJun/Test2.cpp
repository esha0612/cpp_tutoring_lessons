// Let's start a bit with algorithms.
// Here is a classic problem: Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// Example:
// Given nums = [2, 7, 11, 15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 = 9, return [0, 1].
// If there are more than one solution, return the first one.
// If no solutions can be found, return [-1, -1].
// Possible optimizations:
// 1. Searching from i+1 to n instead of 0 to n.
// 2. Breaking the loop if the solution is found.

#include <iostream>
#include <algorithm>

using namespace std;

void calculate(int arr[], int target, int size, int *result) {
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size + 1; j++) {
            if (arr[i] + arr[j] == target){
                result[0]=i;
                result[1]=j;
                break;
            }
        }
    }
}

void calculate2(int arr[], int target, int size, int *result) {
    // Instead of searching for n1 + n2 = target, we can search for n2 = target - n1
    // So for each element, we can search for target - element in the array.
    // This will reduce the time complexity in practice.

    for (int i = 0; i < size; i++) {
        int n2 = target - arr[i];
        for (int j = i+1; j < size + 1; j++) {
            if (arr[j] == n2){
                result[0]=i;
                result[1]=j;
                break;
            }
        }
    } 
}

// In this approach, we will sort the array and perform binary search for the target - element.
// This will reduce the time complexity to O(nlogn).
bool binarySearch(int arr[], int low, int high, int target, int &resultIndex) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            resultIndex = mid;
            return true;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

void calculate3(int arr[], int target, int size, int *result) {
    // First, sort the array
    sort(arr, arr + size);

    int resultIndex = -1;
    for (int i = 0; i < size; i++) {
        int n2 = target - arr[i];
        if (binarySearch(arr, i+1, size, n2, resultIndex)) {
            result[0]=i;
            result[1]=resultIndex;
            break;
        }
    } 
}

int main() {
    int arr[] = {2, 7, 11, 15, 3, 6, 8, 9, 10, 12, 0, 13, 14, 16, 17, 18, 19, 20, 21, 22, 23};
    int target = 9;
    int result[2];
    calculate(arr, target, sizeof(arr)/sizeof(int), result);
    cout << arr[result[0]] << " " << arr[result[1]] << endl;

    calculate2(arr, target, sizeof(arr)/sizeof(int), result);
    cout << arr[result[0]] << " " << arr[result[1]] << endl;

    calculate3(arr, target, sizeof(arr)/sizeof(int), result);
    cout << arr[result[0]] << " " << arr[result[1]] << endl;
    return 0;
}