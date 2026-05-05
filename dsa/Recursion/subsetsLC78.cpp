#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
Given an array nums, generate all possible subsets (power set).

Example:
Input: [1,2,3]
Output: [[], [1], [2], [1,2], [3], [1,3], [2,3], [1,2,3]]
Approach: Recursion (Pick / Not Pick)

At every index, you have 2 choices:
-> Exclude the element
-> Include the element

So for n elements → total subsets = 2ⁿ

-->Why this approach works
Subsets = combinations of elements
Each element either appears or doesn’t appear
This naturally forms a binary decision tree
FULL Recursion Tree (for [1,2,3])
                                   []
                         /                     \
                    exclude 1               include 1
                    []                        [1]
                 /      \                 /        \
          exclude 2   include 2     exclude 2   include 2
            []           [2]          [1]         [1,2]
          /   \        /    \       /    \       /     \
       ex3   in3    ex3    in3    ex3    in3   ex3     in3

       []   [3]    [2]   [2,3]   [1]   [1,3]  [1,2]  [1,2,3]

Final Answer:
[], [3], [2], [2,3], [1], [1,3], [1,2], [1,2,3]

--> Code Flow Intuition
At each call:

// exclude
solve(nums, output, index+1, ans);

// include
output.push_back(nums[index]);
solve(nums, output, index+1, ans);

--> Base Case
if (index >= nums.size()){
    ans.push_back(output);
    return;
}
When we processed all elements → store current subset


--> Key Insight
output is passed by value
→ every recursive call gets its own copy
→ no need for pop_back()


Time Complexity: O(2ⁿ * n)
-> 2ⁿ subsets
-> each subset takes O(n) to copy
Space Complexity: O(n) recursion stack
*/

void solve(vector<int>& nums, vector<int> output, int index, vector<vector<int>>&ans){
    //base case
    if (index >= nums.size()){
        ans.push_back(output);
        return;
    }

    //exclude
    solve(nums, output, index+1, ans);

    //include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index+1, ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
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

/*
--> Conceptual Mistakes to Avoid
1)Thinking this is backtracking
This is actually recursion with copies
No undo step needed

2)Confusing include/exclude order
Order doesn’t matter
Just be consistent


-->GOLDEN Interview Tips
Tip 1: Always say this line
“At each index, I have two choices — include or exclude — leading to 2ⁿ subsets.”

Tip 2: Mention recursion tree
Interviewers LOVE this:
“This forms a binary recursion tree of height n.”

Tip 3: Optimize discussion
If interviewer pushes:
You can do bitmasking
Or iterative approach

Tip 4: Variant questions
Be ready for:
-Subsets II (duplicates) → need sorting + skip duplicates
-Combination Sum
-Permutations

Tip 5: If asked to optimize space
Switch to:
-vector<int>& output
-use pop_back()
*/