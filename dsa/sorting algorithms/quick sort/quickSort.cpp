#include <bits/stdc++.h>
using namespace std;

/*

    - Divide & Conquer algorithm
    - Pick a pivot, place it at correct position
    - Recursively sort left and right parts

    PROPERTIES:
    In-place → does NOT use extra array space
       (only recursion stack → O(log n) avg)

    Not stable → equal elements may change order

    TIME COMPLEXITY:
    Best/Average → O(n log n)
    Worst        → O(n^2) (when pivot is worst choice)

    WHY USED FOR ARRAYS?
    - Cache friendly (contiguous memory access)
    - No extra space like MergeSort
    - Faster in practice despite same complexity

    WHY NOT FOR LINKED LISTS?
    - No random access (arr[i] not possible)
    - Swapping is costly (pointer changes)

    WHY MERGESORT FOR LINKED LISTS?
    - Works via pointer manipulation (no extra space)
    - Stable
    - Guaranteed O(n log n)
*/


/*
    FUNCTION: partition

    PURPOSE:
    - Places pivot at its correct sorted position
    - Left side → elements < pivot
    - Right side → elements > pivot

    STEPS:
    1. Choose pivot (first element)
    2. Count elements smaller than pivot
    3. Place pivot at correct index
    4. Fix left and right sides using 2-pointer approach

    IMPORTANT IDEA:
    - First FIND misplaced elements using pointers
    - THEN swap (not directly rely on condition)
*/
int partition(vector<int>& arr, int start, int end) {

    // Step 1: Choose pivot
    int pivot = arr[start];

    // Step 2: Count elements smaller than pivot
    int smallerThanPivot = 0;
    for(int i = start + 1; i <= end; i++) {
        if(arr[i] < pivot) smallerThanPivot++;
    }

    // Step 3: Place pivot at correct position
    int pivotIndex = start + smallerThanPivot;
    swap(arr[pivotIndex], arr[start]);

    // Step 4: Fix elements around pivot
    int i = start, j = end;

    while(i < pivotIndex && j > pivotIndex) {

        /*
            Move i forward until we find WRONG element
            (element > pivot on left side)
        */
        while(arr[i] < pivot) i++;

        /*
            Move j backward until we find WRONG element
            (element < pivot on right side)
        */
        while(arr[j] > pivot) j--;

        /*
            Swap misplaced elements

            NOTE:
            We DO NOT directly use:
                arr[i] > pivot && arr[j] < pivot

            WHY?
            - That condition alone does not guarantee movement
            - Can cause infinite loops
            - Instead:
                → first move pointers
                → then swap if needed
        */
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}


/*
    FUNCTION: quickSort

    PURPOSE:
    - Recursively sorts array

    LOGIC:
    1. Partition → pivot gets correct position
    2. Sort left part
    3. Sort right part

    IMPORTANT:
    - Pivot should NOT be included again
      → use (pivot - 1) and (pivot + 1)
*/
void quickSort(vector<int>& arr, int start, int end) {

    // Base case
    if(start >= end) return;

    // Step 1: Partition
    int pivot = partition(arr, start, end);

    // Step 2: Sort left half
    quickSort(arr, start, pivot - 1);

    // Step 3: Sort right half
    quickSort(arr, pivot + 1, end);
}


int main() {
    vector<int> arr = {3, 1, 4, 2};

    quickSort(arr, 0, arr.size() - 1);

    for(int x : arr) cout << x << " ";
}