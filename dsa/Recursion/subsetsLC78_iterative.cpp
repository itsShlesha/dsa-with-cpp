#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>&nums){
    int n = nums.size();
    int total = 1 << n;     //2^n elements

    vector<vector<int>> ans;
    for(int mask = 0; mask < total; mask++){
        vector<int>subset;
        //check if ith bit is ON;
        for(int i=0; i<n; i++){
            if(mask & (1<<i)) subset.push_back(nums[i]);
        }
        ans.push_back(subset);
    }
    return ans;
}

int main(){
    cout<<"Enter the no. of elements in an array to obtain powerset: "<<endl;
    int n;
    cin>>n; vector<int> arr(n);
    for(int i=0; i<n; i++){
        cout<<"Enter Element "<<i<<" : ";
        cin>>arr[i];
    }
    cout<<endl<<"Subsets of entered array are: "<<endl;
    vector<vector<int>> ans = subsets(arr);
    for(auto x : ans){
        cout << "[ ";
        for(auto y : x){
            cout << y << " ";
        }
        cout << "]\n";
    }   
}