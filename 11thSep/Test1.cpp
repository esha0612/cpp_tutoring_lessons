// For the first test, we will check basic control flow, starting with loops.

#include <iostream>

using namespace std;

int calculate_median(int* arr, int size) {
    // A median is defined as the middle element of a sorted array.
    // The array you receive may not be sorted, so you need to sort it first.
    // If the size of the array is even, the median is the average of the two middle elements.
    int j, i;
    bool flag;
    for ( i = 0; i < size-1; i++) {
        flag=false;
        for (j = 0; j < size-i-1; j++) {
            if (arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
    }
    // Make it one line
    return size%2==0 ? (arr[size/2]+arr[size/2-1])/2 : arr[size/2]; 



}



int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << calculate_median(arr, size) << endl;

    return 0;
}