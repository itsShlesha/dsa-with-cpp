#include <bits/stdc++.h>
using namespace std;

/*
Find first and last occurrence of a key in a sorted array
Time complexity : O(log n)
pro tip -> to find the total no. of occurrences of an element, return: (lastOccurence - firstOccurence)+1
*/

int firstOccurrence(vector<int>& arr, int size, int key){
    int low = 0;
    int high = size-1;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;

        if(key == arr[mid]){
            ans = mid;
            high = mid-1;
        }
        else if(key < arr[mid]) high = mid-1;
        else if(key > arr[mid]) low = mid+1;
    }
    return ans;
}

int lastOccurrence(vector<int>& arr, int size, int key){
    int low = 0;
    int high = size-1;
    int ans = -1;
        while(low<=high){
        int mid = low + (high-low)/2;

        if(key == arr[mid]){
            ans = mid;
            low = mid+1;
        }
        else if(key < arr[mid]) high = mid-1;
        else if(key > arr[mid]) low = mid+1;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k){
    return { firstOccurrence(arr, n, k),
             lastOccurrence(arr, n, k) };
}

int main(){
    vector<int> arr = {1, 2, 2, 3, 3, 5};

    pair<int, int> result = firstAndLastPosition(arr, arr.size(), 3);

    cout << "First occurrence: " << result.first << endl;
    cout << "Last occurrence: " << result.second << endl;

    return 0;
}