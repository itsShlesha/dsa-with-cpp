#include <bits/stdc++.h>
using namespace std;

/*
To find the pivot index in a rotated array.
"The index at which the original sorted order breaks due to rotation is called the pivot index."
-> typically the index of the smallest element (rotation point)
and hence, on the left of the pivot lie the larger elements and on the right of the pivot lie the smaller ones.

Time complexity -> O(log n)
*/

int pivotIndex(vector<int>& arr){
    int low = 0, high = arr.size()-1, mid;
    while(low < high){
        mid = low + (high-low)/2;
        if(arr[mid] > arr[high]) low = mid+1;
        else if(arr[mid] < arr[high]) high = mid;
    }
    return low;
}

int main(){
    vector<int> arr = {5, 1, 2, 3, 4};
    cout<<"The pivot index of arr is: "<<pivotIndex(arr)<<endl;

    return 0;
}

/*
Mistakes (I made) to avoid:
>> Initially, I treated the rotated array like a mountain array, but that fails 
because rotated arrays aren’t locally monotonic.

-> Instead of comparing with neighbors, I compare mid with high 
to determine which sorted half I’m in and move towards the smallest element, which is the pivot.

-> Binary search works only when a comparison gives GLOBAL direction, not just local slope.
*/