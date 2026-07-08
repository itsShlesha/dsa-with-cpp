#include <bits/stdc++.h>
using namespace std;

#define MAX 100

/*
===========================================================
PROBLEM: Maximum Rectangle in a Binary Matrix
===========================================================

Problem Statement:
Given a binary matrix consisting of only 0s and 1s,
find the area of the largest rectangle containing
only 1s.

-----------------------------------------------------------
APPROACH
-----------------------------------------------------------

Idea:
Treat every row as the base of a histogram.

Step 1:
Compute the largest rectangle for the first row
using the Largest Rectangle in Histogram algorithm.

Step 2:
For every remaining row,

If current cell is 1,
add the value from the previous row.

If current cell is 0,
keep it as 0.

This converts each row into histogram heights.

Step 3:
Find the largest rectangle in this updated histogram.

Keep updating the maximum area.

-----------------------------------------------------------
WHY THIS APPROACH WORKS
-----------------------------------------------------------

Each row represents the bottom boundary of a possible
rectangle.

Updating the matrix stores the consecutive number of
1s vertically.

Once heights are known, the histogram algorithm
efficiently computes the largest rectangle ending
at that row.

The maximum among all rows is the required answer.

-----------------------------------------------------------
TIME COMPLEXITY
-----------------------------------------------------------

Building histograms : O(N × M)

Largest Histogram (each row) : O(M)

Total :
O(N × M)

-----------------------------------------------------------
SPACE COMPLEXITY
-----------------------------------------------------------

O(M)

(Stacks and helper arrays used while computing
largest histogram.)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int>& arr, int n) {

    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {

        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }

        ans[i] = s.top();

        s.push(i);
    }

    return ans;
}

vector<int> prevSmallerElement(vector<int>& arr, int n) {

    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = 0; i < n; i++) {

        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }

        ans[i] = s.top();

        s.push(i);
    }

    return ans;
}

int largestRectangularArea(vector<int>& height) {

    int n = height.size();

    vector<int> next = nextSmallerElement(height, n);
    vector<int> prev = prevSmallerElement(height, n);

    int area = 0;

    for (int i = 0; i < n; i++) {

        int length = height[i];

        if (next[i] == -1)
            next[i] = n;

        int breadth = next[i] - prev[i] - 1;

        int newArea = length * breadth;

        area = max(area, newArea);
    }

    return area;
}

int maxArea(vector<vector<int>>& M, int n, int m) {

    // Compute area for first row
    int area = largestRectangularArea(M[0]);

    // Update remaining rows
    for (int i = 1; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (M[i][j] != 0)
                M[i][j] += M[i - 1][j];
            else
                M[i][j] = 0;
        }

        area = max(area, largestRectangularArea(M[i]));
    }

    return area;
}

int main() {

    vector<vector<int>> M = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    int n = M.size();
    int m = M[0].size();

    cout << "Maximum Rectangle Area = " << maxArea(M, n, m);

    return 0;
}

/*
===========================================================
IMPORTANT NOTES / INTERVIEW TIPS
===========================================================

Mistakes to Avoid
-----------------
1. Forgetting to replace next[i] with n when it is -1.

2. Breadth formula should always be:
   next[i] - prev[i] - 1

3. While updating histogram,
   add only when current value is 1.

4. Reset height to 0 whenever matrix value is 0.

5. Don't forget to compute area for the first row
   before updating remaining rows.

-----------------------------------------------------------
INTERVIEW INSIGHT
-----------------------------------------------------------

This problem is an extension of
Largest Rectangle in Histogram.

Instead of solving directly on a matrix,
convert every row into a histogram and
reuse the histogram solution.

-----------------------------------------------------------
PATTERN
-----------------------------------------------------------

✓ Stack
✓ Monotonic Stack
✓ Histogram
✓ Matrix
✓ Dynamic Height Building

-----------------------------------------------------------
GOLDEN TIP
-----------------------------------------------------------

Whenever a matrix problem involves finding the
largest rectangle of consecutive 1s, think about
converting each row into histogram heights.

The histogram solution can then be reused without
any modification.

-----------------------------------------------------------
ONE-LINE SUMMARY
-----------------------------------------------------------

Convert every row into a histogram and apply the
Largest Rectangle in Histogram algorithm on each row.
*/