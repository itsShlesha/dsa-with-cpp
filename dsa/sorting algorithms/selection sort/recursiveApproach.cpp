#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>&arr, int i, int size){
    if(i >= size-1) return;

    int mini = i;
    for(int j = i+1; j<size; j++){
        if(arr[j]<arr[mini]) mini = j;
    }
    swap(arr[i],arr[mini]);

    selectionSort(arr,i+1,size);
}

int main(){
    vector<int>arr= {12,56,8,23,23,14};
    selectionSort(arr,0,arr.size());
    for(int x:arr){
        cout<<x<<" ";
    }
}