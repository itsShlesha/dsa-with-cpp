#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>&arr, int size){
    if(size<=1) return;

    insertionSort(arr,size-1);

    int temp = arr[size-1];
    int j = size-2;

    while(j>=0 && arr[j]>temp){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = temp;
}

int main(){
    vector<int> arr = {12,56,8,23,23,14};
    insertionSort(arr,arr.size());
    for(int x:arr){
        cout<<x<<" ";
    }
}