#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM:
Move all zeroes in the given array to the end while maintaining
the relative order of the non-zero elements.

APPROACH:
I used the two-pointer technique.
One pointer (`j`) scans the entire array, while the other pointer (`i`)
tracks the position where the next non-zero element should be placed.
Whenever a non-zero element is found, it is swapped with the element
at index `i`, and `i` is incremented.

WHY THIS WORKS:
Each non-zero element is moved forward in order, and all zeroes
are automatically pushed toward the end of the array.
This is done in-place without using any extra memory.

TIME COMPLEXITY:
O(n) — the array is traversed once.
SPACE COMPLEXITY:
O(1) — constant extra space.
*/

void moveZeroes(vector<int>& arr1){
    int i=0;
    for(int j=0; j<arr1.size(); j++){
        if(arr1[j] != 0){
            swap(arr1[j], arr1[i]);
            i++;
        }
    }
}

int main(){

    vector<int> arr = {0,2,0,1,3,0,0};
    moveZeroes(arr);

    for(int x:arr){
        cout<<x<<" ";
    }

    return 0;
}

/*
MISTAKES TO AVOID (LESSONS LEARNED):
1. Causing infinite loops:
   - Forgetting to increment loop variables when using a `while` loop.

2. Mixing up pointer responsibilities:
   - One pointer should scan the array, and the other should track
     the position to place non-zero elements.

3. Overcomplicating conditions:
   - Only checking for non-zero elements is sufficient.
     No need to check both pointers' values.

4. Assuming order doesn’t matter:
   - This approach preserves the relative order of non-zero elements,
     which is often a requirement in interview problems.
*/
