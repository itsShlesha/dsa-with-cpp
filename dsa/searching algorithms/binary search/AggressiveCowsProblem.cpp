#include <bits/stdc++.h>
using namespace std;

/*
Problem: Aggressive Cows

Given:
- n stalls with positions given in an array
- k cows to place
- each stall can have at most one cow

Goal:
Place k cows in stalls such that the minimum distance between
any two cows is maximized.

Approach & Concept:
This is a Binary Search on Answer problem.

We are not searching for stall indices,
we are searching for the maximum possible minimum distance
between any two cows.

Search Space:
- s = 0
- e = maximum stall position

mid represents the minimum distance we are trying to maintain
between every pair of cows.

Why binary search works:
If it is possible to place all cows with minimum distance = mid,
then it will also be possible for any smaller distance.
So the feasibility function is monotonic.

Working:
1. First sort the stalls array.
2. Place the first cow at the first stall.
3. Try placing remaining cows greedily:
   - place a cow only if distance from last placed cow >= mid
4. If we can place k cows, mid is a valid answer.

Binary Search Logic:
- If mid is possible:
    store it as answer
    try for a bigger distance (s = mid + 1)
- If mid is not possible:
    reduce distance (e = mid - 1)

Time Complexity:
O(n log(max_position))

Space Complexity:
O(1)
*/


bool isPossible(vector<int>& stalls, int k, int mid){
    int cowCount = 1;
    int lastPos = stalls[0];

    for(int i=0; i<stalls.size(); i++){
        if(stalls[i] - lastPos >= mid){
            cowCount++;
            if(cowCount==k) return true;
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int>& stalls,int k){
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int e = *max_element(stalls.begin(), stalls.end());
    int ans = -1, mid;
    while(s<=e){
        mid = s +(e-s)/2;
        if(isPossible(stalls, k, mid)){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> stalls = {4,2,1,3,6};
    int k = 2;
    cout<<"The maximum distance between the stalls: "<<aggressiveCows(stalls, k);

    return 0;
}

/*
Mistakes to avoid / Key points:

>> This is binary search on the answer, not on indices.

>> Stalls must be sorted before applying binary search.

>> cowCount represents how many cows have been placed so far.
   Start with 1 because the first cow is placed at stalls[0].

>> lastPos stores the position of the last placed cow.
   Distance is always checked from this.

>> Greedy placement works because we always place cows
   as early as possible.

>> If cowCount reaches k, we can immediately return true.

>> If we cannot place all cows, mid is not feasible.

>> s = 0 is valid for defining the search space
   as long as feasibility is handled correctly.

>> Binary search movement:
   - possible → s = mid + 1 (maximize distance)
   - not possible → e = mid - 1

>> ans should store the last valid distance.
*/
