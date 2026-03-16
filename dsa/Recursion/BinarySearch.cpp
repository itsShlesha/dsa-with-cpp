#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int size, int low, int high, int key){
    if(low>high) return -1;

    int mid = low + (high-low)/2;

    if(arr[mid] == key) return mid;
    else if(arr[mid]>key) return BinarySearch(arr, size, low, mid-1, key);
    else return BinarySearch(arr, size, mid+1, high, key);
}

int main(){
    int arr[] = {1,2,3,4}, size = 4;
    cout<<BinarySearch(arr, size, 0, size-1, 4);
}