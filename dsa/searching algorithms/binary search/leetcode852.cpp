#include <bits/stdc++.h>

/*
-> Mountain array = strictly increasing → strictly decreasing
-> We search for peak index, not a value
-> Binary search works because the array is unimodal

Key idea (slope check):
1.arr[mid] < arr[mid+1] → go right
2.arr[mid] > arr[mid+1] → peak at mid or left

Rules:
1.Never discard mid if it can be the peak
2.Loop while low < high
3.Stop at low == high
4.Return the converged pointer, not mid

MOST IMPORTANT:
-> Always dry-run — binary search bugs hide in pointer movement.
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0, high=arr.size()-1, mid; 
        while(low<high){
            mid = low + (high-low)/2;
            if(arr[mid] < arr[mid+1]){ low = mid+1;}
            else if(arr[mid] > arr[mid+1]){ high = mid;}
        }
        return low;
    }
};