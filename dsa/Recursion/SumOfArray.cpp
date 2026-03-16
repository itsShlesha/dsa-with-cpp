#include <bits/stdc++.h>
using namespace std;

int SumOfArray(int arr[], int size){
    if(size==0) return 0;
    return arr[size-1] + SumOfArray(arr,size-1);
}

int main(){
    int arr[] = {1,2,3,4}, size = 4;
    cout<<SumOfArray(arr, size);
}