#include <bits/stdc++.h>
using namespace std;

/*
Binary Search
Precondition: Array must be sorted
Time Complexity: O(log n)
*/

//recursive approach
int recursive_binary_search(int* arr, int key, int low, int high){
    if(low>high) return -1; //key not found

    int mid = low + (high-low)/2;

    if(key == arr[mid]) return mid;
    else if(key > arr[mid]) return recursive_binary_search(arr, key, mid+1, high); 
    else return recursive_binary_search(arr, key, low, mid-1); //key < arr[mid]
}

//iterative approach
int iterative_binary_search(int* arr, int key, int low, int high){
    while(low<=high){
    int mid = low + (high-low)/2;
    
        if(key > arr[mid]) low= mid+1;
        else if(key < arr[mid]) high = mid-1;
        else return mid; //else if(key == arr[mid])
    }
    return -1; //key not found
    }

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Recursive: Index of 4 = "
         << recursive_binary_search(arr, 4, 0, n - 1) << endl;

    cout << "Iterative: Index of 4 = "
         << iterative_binary_search(arr, 4, 0, n - 1) << endl;

    return 0;
}