#include <bits/stdc++.h>
using namespace std;

/*
-->Problem Statement
Given a string str, generate all possible subsequences.

->A subsequence:
Maintains order
Can skip characters
Can be empty (optional based on problem)

Example:
Input: "abc"
Output: a, b, c, ab, ac, bc, abc
Approach: Recursion (Include / Exclude)

At every index:
Exclude current character
Include current character
Same exact idea as subsets.

--> Why this approach works
Each character has 2 choices
Total subsequences = 2ⁿ
Naturally forms a binary recursion tree

--> Code Flow
// exclude
solve(str, output, index+1, ans);

// include
output.push_back(str[index]);
solve(str, output, index+1, ans);

--> Base Case
if(index >= str.length()){
    if(output.length() > 0)
        ans.push_back(output);
    return;
}
When we reach end → one subsequence formed
You’re skipping empty subsequence using condition

FULL Recursion Tree (for "abc")
                                   ""
                        /                         \
                  exclude a                   include a
                    ""                         "a"
                 /     \                    /        \
           ex b       in b            ex b          in b
            ""        "b"             "a"           "ab"
           / \       /   \           /   \         /    \
        ex c in c  ex c in c     ex c in c     ex c    in c

        ""  "c"   "b"  "bc"     "a"  "ac"     "ab"   "abc"

->After removing empty:
c, b, bc, a, ac, ab, abc

-->Key Insight
output is passed by value
→ no need for pop_back()

Time Complexity: O(2ⁿ * n)
Space Complexity: O(n)  //recursion stack
*/

void solve(string str, string output, int index, vector<string>&ans){
    //base case
    if(index >= str.length()){
        if(output.length() > 0)
            ans.push_back(output);
        return;
    }

    //exclude
    solve(str, output, index+1, ans);

    //include
    char element = str[index];
    output.push_back(element);
    solve(str, output, index+1, ans);
}

vector<string> subsequences(string str){
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, output, index, ans);
    return ans;
}

int main(){
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    vector<string> ans = subsequences(str);

    for(auto x : ans){
        cout<<x<<endl;
    }
}

/*
--->>Conceptual Mistakes to Avoid
1)Thinking subsequence = substring
Subsequence → skip allowed
Substring → continuous
2)Forgetting order matters
"ac" is valid
"ca" is NOT

-->GOLDEN Interview Tips
Tip 1: Say this confidently
“Each character has two choices — include or exclude — leading to 2ⁿ subsequences.”

Tip 2: Mention recursion tree
“This forms a binary tree of height n.”

Tip 3: Clarify empty subsequence
Ask:
“Should I include empty string?”

Tip 4: Optimization discussion
Can use bitmasking
Same logic as subsets

Tip 5: Pattern recognition
->This pattern applies to:
Subsequences
Subsets
Combination problems
*/