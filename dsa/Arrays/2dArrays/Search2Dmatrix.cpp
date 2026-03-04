#include <bits/stdc++.h>
using namespace std;

/*
binary search on a matrix where each row is sorted in ascending order 
and every first element of a row is greater than last element of previous row
*/

 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = row*col - 1;

        while(start<=end){
            int mid = (start+end)/2;
            int element = matrix[mid/col][mid%col];
            if(element==target) return 1;
            else if(element < target) start = mid+1;
            else end = mid-1;
        }
        return 0;
    }

int main(){
    vector<vector<int>> matrix = {{1,2,},{4,6},{7,8}};
    cout<<searchMatrix(matrix, 10);
}