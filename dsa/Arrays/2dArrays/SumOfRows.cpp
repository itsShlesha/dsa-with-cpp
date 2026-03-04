#include <bits/stdc++.h>
using namespace std;

void display(int arr[][3], int row, int col){
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void sumOfRows(int arr[][3], int row, int col){
    int sum;
    for(int i = 0; i<row; i++){
        sum = 0;
        for(int j = 0; j<col; j++){
            sum = sum + arr[i][j];
        }
        cout<<"Sum of row "<<i<<": "<<sum<<endl;
    }
}

void LargestRowSum(int arr[][3], int row, int col){
    int sum, max = 0, maxi;
    for(int i = 0; i<row; i++){
        sum = 0;
        for(int j = 0; j<col; j++){
            sum = sum + arr[i][j];
        }
        if(sum>max){max=sum; maxi = i;}
    }
    cout<<"The largest row sum is: "<<max<<" of row: "<<maxi<<endl;
}

int main(){
    int arr[3][3] = {22,56,89,100,45,11,12,56,0};
    display(arr,3,3);
    sumOfRows(arr,3,3);
    LargestRowSum(arr,3,3);
}