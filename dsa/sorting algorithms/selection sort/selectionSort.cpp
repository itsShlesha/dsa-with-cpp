#include <bits/stdc++.h>
using namespace std;

/*
SELECTION SORT

Approach:
- The array is divided into two parts: sorted and unsorted.
- Initially, the sorted part is empty.
- For each index i (0 to n-2), assume the current element as minimum.
- Traverse the unsorted part to find the actual minimum element.
- Swap the minimum element with the element at index i.
- After each pass, the sorted portion grows from the left.

Time Complexity:
- Best Case: O(n^2)
- Average Case: O(n^2)
- Worst Case: O(n^2)
Reason: For every element, we scan the remaining array to find the minimum,
regardless of the input order.

Space Complexity:
- O(1)
Selection Sort is an in-place sorting algorithm.

Use Cases:
- When extra memory usage is not allowed.
- When the number of swaps needs to be minimized.
- Suitable for small datasets and learning basic sorting concepts.
*/


void SelectionSort(vector<int>& arr){
    for(int i=0; i<arr.size()-1; i++){
        int minIndex = i;
        for(int j=i+1; j<arr.size(); j++){
            if(arr[minIndex] > arr[j]) minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main(){

    vector<int> v = {64,25,12,22,11};
    SelectionSort(v);
    cout<<"The sorted array: "<<endl;
    for(int x: v){
        cout<<x<<endl;
    }

    return 0;
}

/*
MISTAKES TO AVOID (COMMON BUGS I MADE):

- Running the outer loop till n instead of n-1.
- Swapping elements inside the inner loop instead of after finding minIndex.
- Forgetting to reinitialize minIndex = i for each pass.
- Trying to print the sorting function directly when it returns void.
- Confusing selection sort with bubble sort (selection sort does not swap adjacent elements).
*/
