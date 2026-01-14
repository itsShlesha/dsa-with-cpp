#include <bits/stdc++.h>
using namespace std;

/*
INSERTION SORT

Approach:
- Divide the array into sorted and unsorted parts.
- Initially, the first element is considered sorted.
- Pick the next element from the unsorted part.
- Shift elements of the sorted part that are greater than the picked element.
- Insert the picked element at its correct position.
- Repeat until the entire array is sorted.

Time Complexity:
- Best Case: O(n)
  (When the array is already sorted; no shifts needed)
- Average Case: O(n^2)
- Worst Case: O(n^2)
  (When the array is reverse sorted)

Space Complexity:
- O(1)
Insertion sort is an in-place sorting algorithm.

Properties:
- Stable sorting algorithm.
- Adaptive (works faster for nearly sorted arrays).

Use Cases:
- When the input size is small.
- When the array is nearly sorted.
- Used in practice for small subarrays (e.g., inside hybrid algorithms).
- Good for online sorting (elements arrive one by one).
*/

void insertionSort(vector<int>& arr){
     int i=1;
    while(i<arr.size()){
       int j=i-1;
        int temp=arr[i];
        while(j>=0){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
            j--;
        }
        i++;
        arr[j+1]=temp;
    }
}


int main(){
    vector<int> arr = {6,5,4,3,2,1};
    insertionSort(arr);
    for(int x:arr){
        cout<<x<<endl;
    }
    return 0;
}

/*
MISTAKES TO AVOID (COMMON BUGS I MADE):

- Starting the loop from index 0 instead of 1.
- Forgetting to store arr[i] in a temp variable.
- Overwriting elements without shifting properly.
- Misplacing the insertion position (arr[j+1]).
- Using swap instead of shifting (inefficient for insertion sort).
*/