#include <bits/stdc++.h>
using namespace std;

/*
INVERSION COUNT USING MERGE SORT

Definition:
An inversion is a pair (i, j) such that:
    i < j AND arr[i] > arr[j]

Goal:
Count total number of such pairs.

----------------------------------------------------
APPROACH: Merge Sort + Counting
----------------------------------------------------

Divide:
- Split array into two halves

Conquer:
- Count inversions in left half
- Count inversions in right half

Combine:
- Count cross inversions during merge

----------------------------------------------------
KEY INSIGHT:
----------------------------------------------------
If left[i] > right[j], then:
→ ALL elements from left[i] to left[end] are > right[j]

So:
    inv_count += (len1 - i)

----------------------------------------------------
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

// Merges two sorted halves and counts cross inversions
int merge(int* arr, int s, int e){

    int mid = s + (e - s) / 2;
    int inv_count = 0;

    // Lengths of left and right subarrays
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // Create temporary arrays
    int* left = new int[len1];
    int* right = new int[len2];


    //STEP 1: Copy elements into temp arrays

    int mainArrayIndex = s;

    for(int i = 0; i < len1; i++)
        left[i] = arr[mainArrayIndex++];

    mainArrayIndex = mid + 1;

    for(int i = 0; i < len2; i++)
        right[i] = arr[mainArrayIndex++];

    //STEP 2: Merge + Count inversions

    int index1 = 0, index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2){

        // Case: inversion found
        if(left[index1] > right[index2]){

            /*
            Since left array is sorted,
            all elements from index1 → end are greater

            So add:
                (remaining elements in left)
            */
            inv_count += (len1 - index1);

            // Place smaller element first
            arr[mainArrayIndex++] = right[index2++];

        } else {
            // Normal merge (no inversion)
            arr[mainArrayIndex++] = left[index1++];
        }
    }

    //STEP 3: Copy remaining elements

    while(index1 < len1)
        arr[mainArrayIndex++] = left[index1++];

    while(index2 < len2)
        arr[mainArrayIndex++] = right[index2++];


    // Free memory
    delete[] left;
    delete[] right;

    return inv_count;
}

int mergeSort(int* arr, int s, int e){

    // Base case: single element → no inversion
    if(s >= e) return 0;

    int mid = s + (e - s) / 2;

    int inv_count = 0;

    // Count inversions in left half
    inv_count += mergeSort(arr, s, mid);

    // Count inversions in right half
    inv_count += mergeSort(arr, mid + 1, e);

    // Count cross inversions
    inv_count += merge(arr, s, e);

    return inv_count;
}

int main(){

    int arr[] = {4, 3, 2, 1};

    // Print total inversion count
    cout << "Inversion count: " << mergeSort(arr, 0, 3);
}