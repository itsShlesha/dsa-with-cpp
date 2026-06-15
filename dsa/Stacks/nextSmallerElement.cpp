#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM STATEMENT:

Given an array, find the Next Smaller Element (NSE)
for every element.

Next Smaller Element:
The first element on the right side that is strictly
smaller than the current element.

Example:

Input:
[2, 1, 4, 3]

Output:
[1, -1, 3, -1]

Explanation:
2 -> 1
1 -> no smaller element
4 -> 3
3 -> no smaller element

APPROACH: MONOTONIC STACK

1. Traverse from right to left.
2. Maintain a stack containing potential
   next smaller elements.
3. Remove all elements greater than or equal
   to the current element.
4. Top of stack becomes the answer.
5. Push current element into the stack.

WHY IT WORKS:

For an element arr[i], any value greater than or
equal to arr[i] can never be the next smaller
element for arr[i] or any element to its left.

Therefore we remove such elements and keep only
useful candidates in the stack.

The stack remains monotonically increasing
(from bottom to top).

TIME COMPLEXITY:
O(N)

Each element is pushed once and popped once.

SPACE COMPLEXITY:
O(N)

Stack + answer array.
*/

vector<int> nextSmallerElement(vector<int> &arr, int n){

    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for(int i = n - 1; i >= 0; i--){

        int curr = arr[i];

        while(s.top() >= curr){
            s.pop();
        }

        ans[i] = s.top();

        s.push(curr);
    }

    return ans;
}

int main(){

    vector<int> arr = {2, 1, 4, 3};
    int n = arr.size();

    vector<int> ans = nextSmallerElement(arr, n);

    cout << "Next Smaller Elements: ";

    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}

/*
MISTAKES TO AVOID:

1. Forgetting to initialize answer size.

Wrong:
vector<int> ans;

Correct:
vector<int> ans(n);

2. Using:

while(s.top() > curr)

instead of

while(s.top() >= curr)

If duplicates exist, equal elements must also
be removed because we need STRICTLY smaller.

3. Traversing left to right.

The next smaller element lies on the RIGHT,
so traversing from right to left makes the
stack naturally represent future elements.

4. Forgetting the sentinel.

s.push(-1);

This avoids empty-stack checks and naturally
represents "no smaller element exists".

5. Confusing value-based stack with index-based stack.

This version stores VALUES.

Many advanced problems (Histogram, Stock Span,
Largest Rectangle, etc.) require storing INDICES.

GOLDEN INTERVIEW TIPS:

1. Whenever you hear:
   - Next Greater
   - Next Smaller
   - Previous Greater
   - Previous Smaller

Think MONOTONIC STACK immediately.

2. The traversal direction depends on where
   the answer lies.

Answer on Right  -> Traverse Right to Left
Answer on Left   -> Traverse Left to Right

3. Learn these four patterns together:

   Next Greater Element
   Next Smaller Element
   Previous Greater Element
   Previous Smaller Element

Only the comparison operator changes.

4. A monotonic stack usually reduces
   O(N²) brute force solutions to O(N).

5. In interviews, first describe the brute force
   O(N²) approach, then optimize using a stack.
   This clearly demonstrates problem-solving ability.
*/