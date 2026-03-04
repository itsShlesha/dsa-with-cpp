#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM:
Traverse a 2D matrix in spiral order and return all elements
in a single vector.

APPROACH:
We maintain four boundaries:
- startRow (top boundary)
- endRow   (bottom boundary)
- startCol (left boundary)
- endCol   (right boundary)

We also track:
- count = number of elements added to result
- total = total elements in matrix

While count < total:
1. Traverse top row (Left → Right), then increment startRow.
2. Traverse right column (Top → Bottom), then decrement endCol.
3. Traverse bottom row (Right → Left), then decrement endRow.
4. Traverse left column (Bottom → Top), then increment startCol.

After completing one full cycle, the boundaries shrink inward,
effectively removing the outer layer of the matrix.

WHY THIS WORKS:
The matrix can be visualized as layers.
Each iteration removes one outer rectangular layer.
By shrinking boundaries after each directional traversal,
we ensure no element is visited more than once.

The condition (count < total) prevents:
- Over-traversal
- Duplicate visits in odd-sized matrices
- Out-of-bounds access

TIME COMPLEXITY:
O(m × n)
Each element is visited exactly once.

SPACE COMPLEXITY:
O(1) auxiliary space.
Only boundary variables and counters are used.
(Result vector takes O(m × n), but that is required output.)
*/

vector<int> spiralOrder(vector<vector<int>> matrix){
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();

    int startRow = 0;
    int endCol = col-1;
    int endRow = row-1;
    int startCol = 0;

    int count = 0; int total = row*col;

    while(count<total){
        for(int index = startCol; index<=endCol && count<total; index++){
            ans.push_back(matrix[startRow][index]); count++; 
        }
        startRow++;
        for(int index = startRow; index<=endRow && count<total; index++){
            ans.push_back(matrix[index][endCol]); count++;
        }
        endCol--;
        for(int index = endCol; index>=startCol && count<total; index--){
            ans.push_back(matrix[endRow][index]); count++;
        }
        endRow--;
        for(int index = endRow; index>=startRow && count<total; index--){
            ans.push_back(matrix[index][startCol]); count++;
        }
        startCol++;
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}};
    vector<int> result = spiralOrder(matrix);
    for(int i=0; i<matrix.size(); i++){
        cout<<result[i]<<" ";
    }
}

/*
MISTAKES TO AVOID (LESSONS LEARNED):

1. Forgetting (count < total) inside loops:
   - Causes duplicate center element or out-of-bounds errors.

2. Using < instead of <= in boundary loops:
   - Spiral traversal uses inclusive boundaries.

3. Updating boundaries before traversal:
   - Always shrink boundary AFTER completing that direction.

4. Not handling edge cases:
   - Single row matrix
   - Single column matrix
   - 1x1 matrix

5. Incorrect parameter type:
   - Matrix must be vector<vector<int>>, not vector<int>.
*/