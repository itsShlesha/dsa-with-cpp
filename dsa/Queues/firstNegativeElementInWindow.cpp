#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
First Negative Integer in Every Window of Size K

Approach:
1. Use a deque to store the indices of negative numbers.
2. Process the first window and add indices of all negative elements.
3. The front of the deque always represents the first negative number
   in the current window.
4. For every new window:
   - Remove indices that are out of the current window.
   - Add the current index if its element is negative.
   - The front of the deque gives the first negative integer.
   - If the deque is empty, push 0 into the answer.

Why it works:
- The deque stores only useful indices (negative numbers).
- Since indices are added in order, the front is always the earliest
  negative number inside the current window.
- Every index is inserted and removed at most once.

Time Complexity: O(N)
Space Complexity: O(K)
-------------------------------------------------------
*/

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int k){
    deque<long long> dq;
    vector<long long> ans;

    // Process first window
    for(int i = 0; i < k; i++){
        if(A[i] < 0){
            dq.push_back(i);
        }
    }

    // Answer for first window
    if(!dq.empty())
        ans.push_back(A[dq.front()]);
    else
        ans.push_back(0);

    // Process remaining windows
    for(int i = k; i < N; i++){

        // Remove elements outside current window
        if(!dq.empty() && i - dq.front() >= k){
            dq.pop_front();
        }

        // Add current element if negative
        if(A[i] < 0){
            dq.push_back(i);
        }

        // Store answer
        if(!dq.empty())
            ans.push_back(A[dq.front()]);
        else
            ans.push_back(0);
    }

    return ans;
}

int main(){

    long long A[] = {12, -1, -7, 8, -15, 30, 16, 28};
    long long N = 8;
    long long K = 3;

    vector<long long> ans = printFirstNegativeInteger(A, N, K);

    for(long long x : ans)
        cout << x << " ";

    return 0;
}

/*
-------------------------------------------------------
Mistakes to Avoid:
1. Don't reprocess the first window inside the sliding loop.
2. Store INDICES in the deque, not the values.
3. Remove expired indices before checking the answer.
4. Push the current index only if the current element is negative.
5. After every window, don't forget to add the answer
   (either the first negative or 0).

⭐ Interview Tip:
- Whenever you hear "first", "maximum", "minimum", or
  "candidate" in a sliding window problem, think of a deque.
- Storing indices instead of values makes it easy to determine
  when an element leaves the window.
- Each element enters and leaves the deque only once,
  giving an optimal O(N) solution.
-------------------------------------------------------
*/