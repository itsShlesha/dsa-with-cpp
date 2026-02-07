#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM:
Check whether a given array is sorted in increasing order
and then rotated exactly once.

APPROACH:
I counted the number of places where the order breaks
(i.e., where arr[i] < arr[i - 1]).
For a rotated sorted array, there should be exactly one such break.
An additional comparison between the last and first elements
is used to correctly validate the circular order after rotation.

WHY THIS WORKS:
A strictly rotated sorted array has only one point where the
increasing order is violated when viewed circularly.
By counting these violations, we can determine whether the
array is sorted and rotated.

TIME COMPLEXITY:
O(n) — the array is traversed once.
SPACE COMPLEXITY:
O(1) — constant extra space.
*/

bool checkRotatedSortedArray(vector<int>&arr){
    int count=0, end = arr.size()-1;
    for(int i=1; i<arr.size(); i++){
        if(arr[i] < arr[i-1]) count++;
    }
    if(arr[end] > arr[0]) count++;
    if(count == 1) return true;
    return false;
}

int main(){

    vector<int>arr = {3,4,5,1,2};
    bool ans = checkRotatedSortedArray(arr);
    cout<<"Is {";
    for(int x:arr){
        cout<<x<<" ";
    }
    cout<<"} a rotated and sorted array?  "<<ans;
}

/*
MISTAKES TO AVOID (LESSONS LEARNED):
1. Double-counting rotation points:
   - A single rotation can appear as two local decreases
     if circular comparison is not handled carefully.

2. Using the wrong comparison for circular check:
   - Comparing arr[end] < arr[0] can falsely increase the count.
   - Using arr[end] > arr[0] correctly validates the rotation.

3. Not defining the problem clearly:
   - Decide whether a fully sorted (non-rotated) array
     should be considered valid or not.

4. Assuming any single drop means rotation:
   - Only exactly one valid circular break confirms rotation.
*/
