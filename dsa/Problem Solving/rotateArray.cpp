#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM:
Rotate the array to the right by `k` positions.

APPROACH:
I used an auxiliary array to store the rotated positions.
For each element at index `i`, its new position after rotation
is calculated using `(i + k) % n`, where `n` is the size of the array.
The element is placed directly at its correct rotated index
in the temporary array.

WHY THIS WORKS:
The modulo operation ensures that indices wrap around the array.
Each element is moved exactly once to its final position,
resulting in a correct rotation.

TIME COMPLEXITY:
O(n) — each element is processed once.
SPACE COMPLEXITY:
O(n) — an extra array is used to store the rotated result.
*/

void rotateArray(vector<int>&arr, int k){
    vector<int> temp(arr.size());
    for(int i=0; i<arr.size(); i++){
        temp[(i+k)%arr.size()] = arr[i];
    }
    arr = temp;
}

int main(){

    vector<int> arr = {1,2,3,4,5};
    rotateArray(arr,2);

    for(int x:arr){
        cout<<x<<" ";
    }

    return 0;
}

/*
MISTAKES TO AVOID (LESSONS LEARNED):
1. Forgetting modulo operation:
   - Without `(i + k) % n`, indices can go out of bounds.

2. Ignoring large values of `k`:
   - Using modulo automatically handles cases where `k > n`.

3. Assuming swapping is sufficient:
   - Rotation is a cyclic shift and cannot be done with
     arbitrary or partial swaps.

4. Confusing rotation direction:
   - This approach performs a RIGHT rotation.
     Left rotation would use `(i - k + n) % n`.
*/
