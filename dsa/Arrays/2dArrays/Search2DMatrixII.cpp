#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM:
Search for a target value in a 2D matrix.

The matrix has the following properties:
- Each row is sorted in ascending order (left → right).
- Each column is sorted birds ascending order (top → bottom).

Return true if target exists, otherwise return false.

------------------------------------------------------------

APPROACH:
We start from the TOP-RIGHT corner of the matrix.

Why top-right?
Because from there:
- Moving LEFT gives smaller numbers.
- Moving DOWN gives larger numbers.

We maintain:
- rowIndex = current row pointer
- colIndex = current column pointer

Initial position:
row_dm = 0
colIndex = col - 1  (top-right element)

While:
rowIndex < total rows
AND
colIndex >= 0

At each step:
1. If current element == target → return true.
2. If current element < target → move DOWN (rowIndex++).
   Because everything left is smaller, so we need bigger numbers.
3. If current element > target → move LEFT (colIndex--).
   Because everything below is larger, so we need smaller numbers.

This eliminates one row or one column every iteration.

------------------------------------------------------------

WHY THIS WORKS:
From the top-right corner:
- Left side contains smaller values.
- Down side contains larger values.

So every comparison allows us to discard:
- One entire row
OR
- One entire column.

Instead of checking all elements (O(n*m)),
we narrow it down smartly.

------------------------------------------------------------

TIME COMPLEXITY:
O(n + m)
In worst case, we move:
- At most n steps down
- At most m steps left

SPACE COMPLEXITY:
O(1)
Only two pointers are used.
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();
        
    int rowIndex = 0;
    int colIndex = col-1;

    while(rowIndex < row && colIndex >= 0){
        int element = matrix[rowIndex][colIndex];
        if(element == target) return 1;
        else if(element<target) rowIndex++;
        else colIndex--;
    }
    return 0;
}

int main(){
    vector<vector<int>> matrix = {{1,2,},{4,6},{7,8}};
    cout<<searchMatrix(matrix, 10);
}

/*
MISTAKES TO AVOID (LESSONS LEARNED):

1. Moving in the wrong direction:
   - If element > target, you MUST go LEFT (colIndex--).
   - Using colIndex++ causes out-of-bounds.

2. Starting from wrong corner:
   - Bottom-left also works.
   - Top-left or bottom-right do NOT allow elimination logic.

3. Not checking bounds properly:
   Condition must be:
   while(rowIndex < row && colIndex >= 0)

4. Forgetting matrix is non-empty:
   Always ensure matrix has at least 1 row and 1 column.

5. Confusing this with binary search matrix (LC 74):
   That problem has a different property and solution.
*/