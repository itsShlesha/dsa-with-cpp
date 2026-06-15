#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM STATEMENT:

Given a histogram where each bar has width 1,
find the largest rectangular area that can be formed.

Example:

Height = [2,1,5,6,2,3]

Answer = 10

Rectangle formed using bars:
5 and 6

Area = 5 × 2 = 10

APPROACH:

For every bar:

1. Find Previous Smaller Element index.
2. Find Next Smaller Element index.

These boundaries determine how far the current
bar can extend while remaining the minimum height.

Width:

nextSmaller - prevSmaller - 1

Area:

height[i] × width

Take maximum over all bars.

WHY IT WORKS:

For a rectangle whose minimum height is height[i]:

- It can expand left until a smaller bar appears.
- It can expand right until a smaller bar appears.

Therefore:

Width =
(next smaller index)
-
(previous smaller index)
-
1

This gives the maximum width possible using
height[i] as the limiting height.

TIME COMPLEXITY:
O(N)

Each index is pushed and popped at most once
in both stack traversals.

SPACE COMPLEXITY:
O(N)

For:
- Next Smaller Array
- Previous Smaller Array
- Stack
*/

vector<int> nextSmallerElement(vector<int>& arr, int n){

    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for(int i = n - 1; i >= 0; i--){

        int curr = arr[i];

        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }

        ans[i] = s.top();

        s.push(i);
    }

    return ans;
}

vector<int> prevSmallerElement(vector<int>& arr, int n){

    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for(int i = 0; i < n; i++){

        int curr = arr[i];

        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }

        ans[i] = s.top();

        s.push(i);
    }

    return ans;
}

int largestRectangularArea(vector<int>& height){

    int n = height.size();

    vector<int> next = nextSmallerElement(height, n);
    vector<int> prev = prevSmallerElement(height, n);

    int area = 0;

    for(int i = 0; i < n; i++){

        int length = height[i];

        if(next[i] == -1){
            next[i] = n;
        }

        int breadth = next[i] - prev[i] - 1;

        int newArea = length * breadth;

        area = max(area, newArea);
    }

    return area;
}

int main(){

    vector<int> height = {2, 1, 5, 6, 2, 3};

    cout << largestRectangularArea(height);

    return 0;
}

/*
MISTAKES TO AVOID:

1. Store INDICES, not values.

Wrong:
s.push(arr[i])

Correct:
s.push(i)

Width calculation requires positions.

------------------------------------------------

2. Forgetting:

if(next[i] == -1)
    next[i] = n;

No smaller element on the right means
the rectangle extends till the end.

------------------------------------------------

3. Using:

for(int i=0; i<=n; i++)

This accesses arr[n].

Always use:

i < n

------------------------------------------------

4. Calculating width before replacing -1.

Wrong order leads to negative widths.

------------------------------------------------

5. Using > instead of >=

Histogram problems usually require:

arr[s.top()] >= curr

to correctly handle duplicate heights.

------------------------------------------------

GOLDEN INTERVIEW TIPS:

1. Largest Rectangle in Histogram is one of
   the most important monotonic stack problems.

2. Learn this sequence:

   Next Smaller
   Previous Smaller
   Largest Rectangle Histogram
   Max Rectangle in Binary Matrix

These build directly on each other.

3. Whenever a problem asks:

   "How far can an element extend?"

Think:
Previous Smaller + Next Smaller.

4. If brute force is O(N²),
   monotonic stacks often reduce it to O(N).

5. The key insight:

The rectangle height is fixed first,
then determine maximum width.

Most beginners try to determine both
simultaneously and get stuck.
*/