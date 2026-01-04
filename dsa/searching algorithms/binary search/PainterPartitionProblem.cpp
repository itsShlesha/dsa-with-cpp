#include <bits/stdc++.h>
using namespace std;

/*
Problem: Painter’s Partition Problem

Given:
- n boards with lengths arr[]
- k painters
- each painter paints only contiguous boards
- a board cannot be split

Goal:
Minimize the maximum time taken by any painter.

Approach & Concept:
This is a Binary Search on Answer problem.

Instead of searching on indices, we search on the possible values
of the maximum time.

Search Space:
- s = 0
- e = sum of all board lengths

mid represents the maximum time allowed for one painter.

Why binary search works:
If it is possible to paint all boards with max time = mid,
then it will also be possible for any value greater than mid.
So the feasibility function is monotonic.

Working:
- For a given mid, check feasibility using isPossible()
- Assign boards contiguously to painters
- If adding a board exceeds mid, assign a new painter
- If painters needed > k, mid is not feasible

If mid is feasible:
- store it as answer
- try to minimize it (e = mid - 1)

If mid is not feasible:
- increase mid (s = mid + 1)

Time Complexity:
O(n log(sum))
where n = number of boards

Space Complexity:
O(1)
*/

bool isPossible(vector<int>& arr, int n, int k, int mid){
    int painterCount = 1;
    int partitionSum = 0;
    
    for(int i=0; i<n;i++){
        if(partitionSum + arr[i] <= mid){
            partitionSum += arr[i];
        }
        else{
            painterCount++;
            if(painterCount > k || arr[i] > mid){
                return false;
            }
            partitionSum = arr[i];
        }
    }
    return true;
}

int partition(vector<int>& arr, int n, int k){
    int s = 0;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    int e = sum;
    int ans = -1, mid;
    while(s<=e){
        mid = s + (e-s)/2;
        if(isPossible(arr,n,k, mid)){
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
    vector<int> arr = {100};
    int k = 3, n = arr.size();
    cout<<"Time taken: "<<partition(arr, n, k);

    return 0;
}

/*
Mistakes to avoid / Key points:

>> This is binary search on the answer, not on array indices.

>> mid must be calculated inside the while loop.

>> Use <= mid when adding board lengths.
   Equal values are valid.

>> Boards must be assigned contiguously.
   Never skip or reorder boards.

>> A single board > mid means mid is invalid.

>> If painterCount > k, mid is not possible.

>> s = 0 is valid as long as invalid mids
   are handled inside isPossible().

>> Always update search space correctly:
   - feasible → e = mid - 1
   - not feasible → s = mid + 1

>> ans should store the last valid mid.
*/
