#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM:
Given an integer n, generate an n x n matrix filled with
numbers from 1 to n² in spiral order.

The spiral pattern follows this direction sequence:
Left → Right
Top → Bottom
Right → Left
Bottom → Top

The filling continues inward layer by layer.

APPROACH:
We treat the matrix as layers controlled by four boundaries:

- startRow → top boundary
- endRow   → bottom boundary
- startCol → left boundary
- endCol   → right boundary

Step 1:
Initialize an n x n matrix using:
vector<vector<int>> result(n, vector<int>(n));

Step 2:
Maintain:
- count = current number to fill (starts from 1)
- total = n * n

Step 3:
While count <= total:
1. Fill top row (Left → Right), then increment startRow.
2. Fill right column (Top → Bottom), then decrement endCol.
3. Fill bottom row (Right → Left), then decrement endRow.
4. Fill left column (Bottom → Top), then increment startCol.

After completing one full cycle, the outer layer is filled,
and boundaries shrink inward.

WHY THIS WORKS:
The matrix can be visualized as concentric rectangular layers.
Each iteration fills one outer layer completely.
Shrinking boundaries ensures:
- No overwriting
- No revisiting elements
- Controlled inward spiral movement

The condition (count <= total) prevents:
- Overfilling
- Accessing invalid positions
- Infinite looping

TIME COMPLEXITY:
O(n²)
Every cell in the matrix is filled exactly once.

SPACE COMPLEXITY:
O(n²)
Space required to store the generated matrix.
Only constant extra variables are used.
*/

vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector<int>(n));
        int row = n;
        int col = n;

        int startRow = 0;
        int endCol = n-1;
        int endRow = n-1;
        int startCol = 0;

        int count = 1;
        int total = n*n;

        while(count<=total){
            for(int index = startCol; index<=endCol && count<=total; index++){
                result[startRow][index] = count; count++;
            }
            startRow++;
            for(int index = startRow; index<=endRow && count<=total; index++){
                result[index][endCol] = count; count++;
            }
            endCol--;
            for(int index = endCol; index>=startCol && count<=total; index--){
                result[endRow][index] = count; count++;
            }
            endRow--;
            for(int index = endRow; index>=startRow && count<=total; index--){
                result[index][startCol] = count; count++;
            }
            startCol++;
        }
        return result;
    }

int main(){
    int n;
    cin>>n;
    vector<vector<int>> result = generateMatrix(n);
    for(int i = 0; i<result.size(); i++){
        for(int j = 0; j<result[0].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
/*
MISTAKES TO AVOID (LESSONS LEARNED):

1. Not initializing the matrix size:
   - Accessing result[i][j] without allocating memory causes runtime error.

2. Incorrect boundary initialization:
   - startCol must begin at 0, not n-1.

3. Using < instead of <= in loops:
   - Spiral traversal uses inclusive boundaries.

4. Wrong loop condition:
   - Using count < total instead of count <= total
     may leave the last cell unfilled.

5. Starting count from 0:
   - The problem requires numbers from 1 to n².
*/