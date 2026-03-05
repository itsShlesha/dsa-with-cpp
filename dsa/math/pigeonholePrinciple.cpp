#include <bits/stdc++.h>
using namespace std;

/*
Subarray Sum Divisible by K

Problem:
Given an array of integers and an integer k,
check if there exists a contiguous subarray
whose sum is divisible by k.

Example:
arr = [23, 2, 4, 6, 7]
k = 6

Subarray: [2, 4]
Sum = 6
6 % 6 = 0

So answer = true



Approach:
We again use Prefix Sum.

prefix[i] = sum of elements from index 0 → i

Example:

arr = [23, 2, 4]

prefix sums:
23
25
29


Now instead of storing prefix sums directly,
we store their remainder when divided by k.

Why?

Because if two prefix sums have the SAME remainder
when divided by k, then their difference is divisible by k.

Math:

prefix[j] - prefix[i] = subarray sum

If

prefix[j] % k == prefix[i] % k

Then

(prefix[j] - prefix[i]) % k = 0

Which means the subarray sum is divisible by k.



Pigeonhole Principle Insight:

Possible remainders when dividing by k are:

0,1,2,...,k-1

Total = k possibilities.

If we keep generating prefix sums,
eventually two of them must share the same remainder.

When that happens → their difference is divisible by k.



Algorithm Steps:

1. Keep calculating prefix sum.
2. Compute remainder = prefixSum % k.
3. If this remainder was seen before,
   then the subarray between those indices
   has sum divisible by k.
4. Otherwise store this remainder.



Time Complexity: O(n)

-> We traverse the array once.



Space Complexity: O(k) or O(n)

-> Hash map stores remainders.
*/

bool checkSubarraySum(vector<int>& nums, int k){

    unordered_map<int,int> mp;
    mp[0] = -1;   // important case

    int prefixSum = 0;

    for(int i = 0; i < nums.size(); i++){

        prefixSum += nums[i];

        int rem = prefixSum % k;

        if(rem < 0) rem += k;

        if(mp.count(rem)){
            return true;
        }

        mp[rem] = i;
    }

    return false;
}

int main(){

    vector<int> arr = {23,2,4,6,7};
    int k = 6;

    if(checkSubarraySum(arr,k)){
        cout<<"Subarray exists";
    }
    else{
        cout<<"No such subarray";
    }

}



/*
Mistakes I Might Make While Solving:

1. Forgetting that we compare REMAINDERS,
   not prefix sums.

2. Not understanding why equal remainders matter.

   prefix[j] % k = prefix[i] % k

   -> prefix[j] - prefix[i] is divisible by k.

3. Forgetting the special case:
   mp[0] = -1

   This handles the case where
   the subarray starting from index 0 works.

4. Not handling negative remainders.



Key takeaway for myself:

-> For subarray problems involving divisibility,
   store prefixSum % k.

-> If two prefix sums give the same remainder,
   the subarray between them must be divisible by k.

-> This is basically Pigeonhole Principle in action.
*/