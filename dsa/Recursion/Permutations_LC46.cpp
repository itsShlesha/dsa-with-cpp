#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>nums, vector<vector<int>>&ans, int index){
    //base case
    if(index>=nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int j = index; j<nums.size(); j++){
        swap(nums[j], nums[index]);
        solve(nums,ans,index+1);
        //backtrack
        swap(nums[j], nums[index]);
    }
}

vector<vector<int>> permute(vector<int>&nums){
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, ans, index);
    return ans;
}

int main(){
    cout<<"Enter the no. of elements in array: ";
    int n; 
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements: "<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    vector<vector<int>> nums = permute(arr);
    cout<<"Possible permutations of array are: "<<endl;
    for(auto x: nums){
        cout<<"[ ";
        for(auto y:x){
            cout<<y;
        }
        cout<<" ]";
    }
}