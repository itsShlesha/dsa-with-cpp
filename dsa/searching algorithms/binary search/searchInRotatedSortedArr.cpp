#include <bits/stdc++.h>
using namespace std;

/*
Problem: Search in a Rotated Sorted Array (distinct elements)

Key idea:
A rotated sorted array is made of two individually sorted subarrays split at the pivot.
Once the pivot (smallest element index) is known, the target must lie in exactly one of these two halves.

Approach:
1. Find the pivot index (index of the smallest element).
2. If target lies between arr[pivot] and arr[high], search in the right half.
3. Otherwise, search in the left half.
4. Apply standard binary search on the chosen sorted half.

Why this works:
Binary search requires a globally sorted range.
The pivot helps identify which subarray is fully sorted and valid for binary search.

Time Complexity:
- Pivot search: O(log n)
- Binary search: O(log n)
Overall: O(log n)
*/

int recursive_binary_search(vector<int>& arr, int key, int low, int high){
    if(low>high) return -1; 

    int mid = low + (high-low)/2;

    if(key == arr[mid]) return mid;
    else if(key > arr[mid]) return recursive_binary_search(arr, key, mid+1, high); 
    else return recursive_binary_search(arr, key, low, mid-1);
}

int pivotIndex(vector<int>& arr){
    int low = 0, high = arr.size()-1, mid;
    while(low < high){
        mid = low + (high-low)/2;
        if(arr[mid] > arr[high]) low = mid+1;
        else if(arr[mid] < arr[high]) high = mid;
    }
    return low;
}

int searchIndex(vector<int>& arr, int target){
    int pivot = pivotIndex(arr), high = arr.size()-1, low = 0, target_index = -1;
    if(target >= arr[pivot] && target <= arr[high]) target_index = recursive_binary_search(arr, target, pivot, high);
    else target_index = recursive_binary_search(arr, target, low, pivot-1);
    return target_index;
}

int main(){

    vector<int> arr = {15,18,20,25,1,3,5,7,10,12};
    cout<<"Index of 7 is: "<<searchIndex(arr, 7)<<endl;

    return 0;
}

/*
Mistakes (I made) to avoid:

>> Comparing target with indices instead of values.
   (Always compare target with arr[low] / arr[mid] / arr[high])

>> Forgetting that the target could be the pivot itself.
   (Use >= and <= when checking the valid search range)

>> Assuming the entire array is sorted.
   (Only one half is sorted after rotation)

>> Treating this like a normal binary search without deciding the correct half first.

Key takeaway:
Binary search works only on a fully sorted range.
In rotated arrays, we must FIRST identify which half is sorted and relevant.
*/
