#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[],int size){
    if(size==0 || size==1){
        return true;
    }
    
    if(arr[0]>arr[1]) return false;
    else{
       bool result = isSorted(arr+1, size-1);
       return result;
    }
}

int main(){
    int arr[] = {1,56,89,1113}; int size = 4;
    cout<<(isSorted(arr, size)?"true":"false");
}