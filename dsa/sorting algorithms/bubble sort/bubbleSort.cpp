#include <bits/stdc++.h>
using namespace std;

/*
BUBBLE SORT

Approach:
- Repeatedly compare adjacent elements.
- If they are in the wrong order, swap them.
- After each pass, the largest element moves (bubbles) to the end.
- With each pass, the size of the unsorted part reduces.
- An optimization is used: if no swaps occur in a pass, the array is already sorted.

Time Complexity:
- Best Case: O(n)
  (When the array is already sorted and no swaps occur)
- Average Case: O(n^2)
- Worst Case: O(n^2)
  (When the array is reverse sorted)

Space Complexity:
- O(1)
Bubble sort is an in-place sorting algorithm.

Use Cases:
- When the input size is small.
- When the array is nearly sorted.
- When stability is required.
- For learning and understanding basic sorting logic.
*/

void bubbleSort(vector<int>& arr){
    for(int i=1; i<arr.size(); i++){
        bool swapped = false;
        for(int j=0; j<arr.size()-i; j++){
            if(arr[j] > arr[j+1]){ swap(arr[j],arr[j+1]); swapped = true; }
        }
        if(swapped==false) break;
    }
}

int main(){
    
    vector<int> v = {6,2,8,4,10};
    bubbleSort(v);
    cout<<"The sorted array: "<<endl;
    for(int x:v){
        cout<<x<<endl;
    }

    return 0;
}

/*
MISTAKES TO AVOID (COMMON BUGS I MADE):

- Running the inner loop till n instead of (n - i).
- Accessing arr[j+1] without proper bounds (out-of-bounds error).
- Forgetting to reset the swapped flag for every pass.
- Not using the swapped optimization, causing unnecessary comparisons.
- Confusing bubble sort with selection sort (bubble uses adjacent swaps).
*/
