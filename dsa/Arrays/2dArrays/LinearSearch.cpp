#include <bits/stdc++.h>
using namespace std;

void display(int arr[][4], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isPresent(int arr[][4], int target, int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j]==target) return true;
        }
    }
    return false;
}

int main(){
    int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    display(arr, 3, 4);
    cout<<"Enter a number to find in array: "<<endl;
    int n; 
    cin>>n;
    cout<<(isPresent(arr,n,3,4)?"found":"not found")<<endl;
}