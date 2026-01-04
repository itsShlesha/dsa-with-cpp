#include <bits/stdc++.h>
using namespace std;

/*
Problem: Split Array Largest Sum (LeetCode 410)

Given:
- an array nums[] of non-negative integers
- an integer k (number of subarrays)

Goal:
Split the array into k or fewer contiguous subarrays
such that the largest subarray sum is minimized.

Approach & Concept:
This is a Binary Search on Answer problem.

We are not searching indices.
We are searching for the minimum possible value of
the maximum subarray sum.

Search Space:
- s = 0
- e = sum of all elements in nums

mid represents the maximum sum allowed for any subarray.

Why binary search works:
If it is possible to split the array such that
no subarray has sum greater than mid,
then it will also be possible for any value greater than mid.

So feasibility is monotonic.

Working:
1. For a given mid, check feasibility using isPossible().
2. Traverse nums and keep adding elements to current subarray.
3. If adding an element exceeds mid:
   - start a new subarray
4. Count how many subarrays are formed.
5. If subarrays needed > k, mid is not valid.

Binary Search Logic:
- If mid is possible:
    store it as answer
    try to minimize further (e = mid - 1)
- If mid is not possible:
    increase mid (s = mid + 1)

Return the minimum valid mid stored.

Time Complexity:
O(n log(sum))

Space Complexity:
O(1)
*/


int isPossible(vector<int>& nums, int k, int mid){
    int elemCount = 1;
    int elemSum = 0;

    for(int i=0; i<nums.size(); i++){
        if(elemSum + nums[i] <= mid){
            elemSum += nums[i];
        }
        else{
            elemCount++;
            if(elemCount > k || nums[i] > mid){
                return false;
            }
            elemSum = nums[i];
        }
    }
    return true;
}

int splitArray(vector<int>& nums, int k){
    int s = 0, sum = 0;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
    }
    int e = sum, ans = -1, mid;
    while(s<=e){
        mid = s + (e-s)/2;
        if(isPossible(nums, k, mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {7,2,5,10,8};
    int k = 2;
    cout<<"The max sum is: "<<splitArray(nums,k);

    return 0;
}

/*
Mistakes to avoid / Key points:

>> This is binary search on the answer, not on indices.

>> Use <= mid when adding elements.
   Exact equality is valid and should NOT cause a split.

>> Using < mid causes extra partitions
   and gives wrong answers (like 19 instead of 18).

>> Subarrays must be contiguous.

>> If nums[i] > mid, mid is immediately invalid.

>> Count starts from 1 because the first subarray always exists.

>> Binary search movement:
   - possible → e = mid - 1
   - not possible → s = mid + 1

>> ans should store the last valid value of mid.

>> s = 0 is valid for defining the search space
   as long as feasibility checks handle invalid mids.
*/
