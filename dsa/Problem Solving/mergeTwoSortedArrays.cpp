#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM:
Merge two sorted arrays into one sorted array.
The first array has extra space at the end to accommodate
all elements of the second array.

APPROACH:
First, copy all elements of the second array into the extra
space of the first array. Then, sort the combined array
using the built-in sort function.

WHY THIS WORKS:
After inserting all elements into one array, sorting ensures
the final array is in non-decreasing order.
This approach prioritizes simplicity and correctness.

TIME COMPLEXITY:
O((m + n) log(m + n)) due to sorting.
SPACE COMPLEXITY:
O(1) extra space (in-place merge using existing array).
*/


void mergeAndSort(vector<int>&arr1, int m, vector<int>&arr2, int n){
    for(int i=m,j=0; i<arr1.size(); i++,j++){
        arr1[i] = arr2[j];
    }
    sort(arr1.begin(), arr1.end());
}

int main(){
    vector<int> arr1 = {1,2,3,0,0,0}; int m = 3;
    vector<int> arr2 = {2,5,6}; int n = 3;

    mergeAndSort(arr1, m, arr2, n);

    for(int x:arr1){
        cout<<x<<" ";
    }

    return 0;
}

/*
MISTAKES TO AVOID (LESSONS LEARNED):
1. Forgetting that arr1 must have size (m + n):
   - Without extra space, inserting arr2 elements will cause errors.

2. Ignoring sorted property:
   - Although both arrays are already sorted, this approach
     does not take advantage of that fact and relies on sorting again.

3. Index mismatch:
   - Ensure the number of elements copied from arr2 matches `n`
     and indices do not go out of bounds.

4. Assuming this is the most optimal solution:
   - This solution is correct but not the most time-efficient.
*/
