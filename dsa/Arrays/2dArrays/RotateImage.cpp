#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM:
Rotate an NxN matrix 90 degrees clockwise.
Do it in-place (no extra matrix allowed).

APPROACH:
Instead of trying to directly move every element to its
new rotated position (which gets messy), we break it into
two simple transformations:

    1) Transpose the matrix
    2) Reverse every row

Why?
Because mathematically:

Original index:      (i, j)
After transpose:     (j, i)
After row reverse:   (j, n-1-i)

And (j, n-1-i) is EXACTLY where a 90° clockwise rotation
sends the element.

So instead of memorizing rotation logic,
we just remember: transpose + reverse rows.

Time Complexity  : O(n^2)
Space Complexity : O(1)
(Everything is done in-place)
*/

 void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size(); int col = matrix[0].size();
        for(int i = 0; i < row; i++){
            for(int j = i; j<col; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i<row; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
/*
MISTAKES TO AVOID: 
- Running j from 0 instead of i (double swap issue)
- Forgetting matrix must be square
- Mixing up clockwise vs anti-clockwise logic

###ANOTHER LOGIC: 4LAYER SWAPPING 
Instead of transpose + reverse, we rotate 4 cells at a time.

Imagine just the outer layer of the matrix:

Top row
Right column
Bottom row
Left column

For each element in that layer, we rotate like this:

top    → right
right  → bottom
bottom → left
left   → top

So one cycle looks like:

temp = top
top = left
left = bottom
bottom = right
right = temp

And we do this for:
Every element in the outer boundary
Then move inward to the next layer
Repeat until reaching the center

Key idea:
1.Number of layers = n/2
2.Each layer shrinks inward

This method:
-Also O(n²)
-Also O(1) space
-Slightly more index-heavy
-But shows deeper matrix understanding in interviews
*/