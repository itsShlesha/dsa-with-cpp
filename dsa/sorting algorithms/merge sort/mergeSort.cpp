#include <bits/stdc++.h>
using namespace std;

/*
MERGE SORT (Divide & Conquer)

Time Complexity:
- Best / Avg / Worst: O(n log n)

Space Complexity:
- O(n) (extra arrays used)

Stable: YES
In-place: NO

Core Idea:
1. Divide array into 2 halves
2. Recursively sort both halves
3. Merge sorted halves
*/


// MERGE FUNCTION
// Merges two sorted halves of array:
// [start ... mid] and [mid+1 ... end]
void merge(int* arr, int start, int end){

    int mid = (start + end) / 2;

    // Lengths of left and right subarrays
    int len1 = mid - start + 1;
    int len2 = end - mid;

    // Create temporary arrays
    int *left = new int[len1];
    int *right = new int[len2];

    //STEP 1: Copy data into temp arrays
    int mainArrayIndex = start;

    // Copy left half
    for(int i = 0; i < len1; i++){
        left[i] = arr[mainArrayIndex++];
    }

    // Copy right half
    mainArrayIndex = mid + 1;
    for(int i = 0; i < len2; i++){
        right[i] = arr[mainArrayIndex++];
    }

    //STEP 2: Merge two sorted arrays
    int index1 = 0;   // pointer for left[]
    int index2 = 0;   // pointer for right[]

    // IMPORTANT: reset index to start
    mainArrayIndex = start;

    // Compare elements and merge
    while(index1 < len1 && index2 < len2){
        if(left[index1] < right[index2]){
            arr[mainArrayIndex++] = left[index1++];
        } else {
            arr[mainArrayIndex++] = right[index2++];
        }
    }

    //STEP 3: Copy remaining elements
    //(Only one of these loops will run)

    while(index1 < len1){
        arr[mainArrayIndex++] = left[index1++];
    }

    while(index2 < len2){
        arr[mainArrayIndex++] = right[index2++];
    }

    // Free allocated memory
    delete[] left;
    delete[] right;
}


/*
MERGE SORT FUNCTION (Recursive)

Base Case:
- If single element → already sorted

Recursive Case:
- Sort left half
- Sort right half
- Merge both
*/
void mergeSort(int* arr, int start, int end){

    // Base case
    if(start >= end) return;

    // Find mid
    int mid = (start + end) / 2;

    // Sort left half
    mergeSort(arr, start, mid);

    // Sort right half
    mergeSort(arr, mid + 1, end);

    // Merge sorted halves
    merge(arr, start, end);
}


int main(){

    int arr[] = {23, 32, 15, 40, 87, 78, 20};
    int n = 7;

    mergeSort(arr, 0, n - 1);

    // Print sorted array
    for(int x : arr){
        cout << x << " ";
    }

    return 0;
}