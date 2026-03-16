#include <bits/stdc++.h>
using namespace std;

int LinearSearch(int arr[], int size, int key){
    if(size==0) return -1;
    if(arr[0]==key) return 0;
    int ans =  LinearSearch(arr+1,size-1,key);

    if(ans == -1) return -1;
    else return ans+1;
}

int main(){
    int arr[] = {12,56,78,10}, size = 4;
    cout<<LinearSearch(arr,size,10);
}