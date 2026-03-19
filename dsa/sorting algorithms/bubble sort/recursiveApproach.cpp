#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&arr, int size){
    if(size == 0 || size == 1) return;

    for(int i = 0; i<size; i++){
        if(arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
    }
    bubbleSort(arr,size-1);
}

int main(){
    vector<int>arr = {56,89,45,78,23,23,5,5920};
    bubbleSort(arr,arr.size());
    for(int x: arr){
        cout<<x<<" ";
    }
}