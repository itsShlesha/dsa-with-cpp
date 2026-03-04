#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM:
Reverse the elements of an array starting from a given index `m`
up to the end of the array.

APPROACH:
I used the two-pointer technique on a subarray.
One pointer starts at index `m` and the other at the last index.
At each step, the elements are swapped and the pointers move inward
until they meet or cross.

WHY THIS WORKS:
Only the required portion of the array is reversed.
Swapping symmetric elements ensures correct placement without
using extra memory.

TIME COMPLEXITY:
O(n - m) — only the subarray from index `m` to the end is traversed.
SPACE COMPLEXITY:
O(1) — in-place reversal with constant extra space.
*/

vector<int> reverseArray(vector<int>&arr, int m){ 
    int start = m;
    int end = arr.size() - 1;
    while(start < end){
        swap(arr[start], arr[end]);
        start++; end--;
    }
    return arr;
}

int main(){

    vector<int> arr = {11,7,3,12,4,56,89};
    vector<int> result = reverseArray(arr,3);
    
    for(int x:result){
        cout<<x<<" ";
    }

    return 0;
}

/*
MISTAKES TO AVOID (LESSONS LEARNED):
1. Ambiguity in problem definition:
   - Be clear whether reversal starts FROM index `m`
     or AFTER index `m` (i.e., `m + 1`).

2. Incorrect loop condition:
   - Using `start > end` will skip the loop entirely.
   - Correct condition is `start < end`.

3. Forgetting pointer updates:
   - Missing `start++` and `end--` leads to an infinite loop.

4. Invalid index values:
   - Ensure `m` is within array bounds before accessing it.
*/

