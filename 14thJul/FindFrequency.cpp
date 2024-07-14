// The objective of this program is to find the frequency of each element in an array.
// Let us add the additional constraints that the array is sorted and the elements are in the range 1 to M.
// M is some maximum integer which is clearly defined.
// The array may have multiple elements with the same value.

#include <iostream>
#include <vector>

using namespace std;

void approach1(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i += count) {
        count=0;
        for (int j = i; j<n; j++){
            if (arr[i]==arr[j]){
                count++;
            }
        }
        cout << "\nFrequency of " << arr[i] << " is: " << count << endl;
    }
}

// Time complexity: O(n)

void approach2(int arr[], int n) {
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1]) {
            count++;
        } else {
            cout << "\nFrequency of " << arr[i-1] << " is: " << count << endl;
            count = 1;
        }
    }
    cout << "\nFrequency of " << arr[n-1] << " is: " << count << endl;
}

// Time complexity: O(n)
// Space complexity: O(1)

// In the next approach, we will use a counting sort (bucket sort) to solve this problem.
// The time complexity of this approach is O(n) and the space complexity is O(M).
// This trades off space for time, based on our estimation of M.
void approach3(int arr[], int n) {
    int M = 5;
    int freq[M] = {0};
    for (int i = 0; i < n; i++) {
        freq[arr[i]-1]++;
    }
    for (int i = 0; i < M; i++) {
        cout << "\nFrequency of " << i+1 << " is: " << freq[i] << endl;
    }
}

// Time complexity: O(n)
// Space complexity: O(M)

// In approach 4, we will use a hash map to solve this problem.
// The time complexity of this approach will be O(mlogn), where m is the number of unique elements in the array.
// If m < M, and M is reasonably close to n, the time complexity can be approximated to O(logn).
// The space complexity of this approach is O(1), as we are using the array itself to store the frequency.

void approach4(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i]--;
    }

    for (int i = 0; i < n; i++) {
        arr[arr[i]%n] += n;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i]/n > 0) {
            cout << "\nFrequency of " << i+1 << " is: " << arr[i]/n << endl;
        }
        arr[i] = arr[i]%n + 1;
    }
}

// In approach 5, we will try to use a hash map with divide and conquer.
// The approach is that we check the first and last element of a given subarray.
// If they are the same, the frequency of that element is (high - low + 1).
// We divide the array into two halves and recursively find the frequency of each element by identifying these end points (/subarrays).
void approach5helper(int arr[], int low, int high, vector<int> &freq) {
    if (low == high) {
        freq[arr[low]]++;
        return;
    }
    int mid = low + (high-low)/2;
    approach5helper(arr, low, mid, freq);
    approach5helper(arr, mid+1, high, freq);
}

void approach5(int arr[], int n) {
    vector<int> freq(n, 0);
    approach5helper(arr, 0, n-1, freq);
    for (int i = 0; i < n; i++) {
        if (freq[i] > 0) {
            cout << "\nFrequency of " << i << " is: " << freq[i] << endl;
        }
    }
}

int main() {
    int arr[] = {1, 1, 2, 2, 2, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Approach 1: ";
    approach1(arr, n);
    cout << endl << "Approach 2: ";
    approach2(arr, n);
    cout << endl << "Approach 3: ";
    approach3(arr, n);
    cout << endl << "Approach 4: ";
    approach4(arr, n);
    cout << endl << "Approach 5: ";
    approach5(arr, n);

    return 0;
}