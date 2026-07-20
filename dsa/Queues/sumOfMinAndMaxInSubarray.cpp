#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------- APPROACH ----------------------------------

Problem:
Given an array and a window size K, find the sum of the maximum and
minimum elements of every subarray of size K.

Algorithm:
1. Maintain two deques:
   - maxi -> stores indices of elements in decreasing order.
   - mini -> stores indices of elements in increasing order.
2. Process the first K elements to initialize both deques.
3. For every remaining element:
   - Add the current window's maximum and minimum to the answer.
   - Remove indices that are outside the current window.
   - Remove smaller elements from the back of maxi.
   - Remove larger elements from the back of mini.
   - Insert the current index into both deques.
4. Finally, add the contribution of the last window.

Example:
Array = [2, -5, -1, 7, -3, -1, -2]
K = 4

Windows:
[2,-5,-1,7]   -> Max = 7, Min = -5, Sum = 2
[-5,-1,7,-3]  -> Max = 7, Min = -5, Sum = 2
[-1,7,-3,-1]  -> Max = 7, Min = -3, Sum = 4
[7,-3,-1,-2]  -> Max = 7, Min = -3, Sum = 4

Total = 12

Time Complexity: O(N)
Space Complexity: O(K)
*/

int solve(int *arr, int n, int k){

    deque<int> maxi;
    deque<int> mini;

    // First window
    for(int i = 0; i < k; i++){

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;

    for(int i = k; i < n; i++){

        ans += arr[maxi.front()] + arr[mini.front()];

        while(!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_front();

        while(!mini.empty() && i - mini.front() >= k)
            mini.pop_front();

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }

    ans += arr[maxi.front()] + arr[mini.front()];

    return ans;
}

int main(){
    int arr[7] = {2, -5, -1, 7, -3, -1, -2};

    cout<<solve(arr, 7, 4)<<endl;
}

/*
--------------------------- INTERVIEW NOTES ----------------------------------

Why does this work?
- The deque stores indices instead of values so we can efficiently
  determine whether an element has moved out of the current window.
- maxi always keeps the largest element of the current window at its front.
- mini always keeps the smallest element of the current window at its front.
- Each element is inserted and removed at most once, giving linear time.

Common Mistakes:
1. Initializing deque<int> maxi(k) instead of deque<int> maxi().
2. Forgetting to maintain the monotonic property before inserting
   the current element.
3. Removing expired indices from the wrong deque.
4. Forgetting to process the last window after the loop.
5. Storing values instead of indices, making window checks impossible.

Key Insight:
A monotonic deque lets us find the maximum or minimum of every sliding
window in O(1) time after O(1) amortized updates, reducing the overall
complexity from O(N*K) to O(N).

Pattern:
Sliding Window + Monotonic Queue (Deque)
(Sum of Minimum and Maximum Elements of All Subarrays of Size K)
*/