#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: Maximum Sum of Non-Adjacent Nodes
-------------------------------------------------------
Approach:
For every node, compute two values:

1. Include Current Node:
   • Add current node's value.
   • Children cannot be included.
   • include = root->data +
               left.exclude +
               right.exclude

2. Exclude Current Node:
   • Current node is skipped.
   • Children may be included or excluded.
   • exclude = max(left.include, left.exclude)
             + max(right.include, right.exclude)

Return both values from every recursive call.

Final answer:
max(include, exclude)

Time Complexity : O(N)
Space Complexity: O(H)
where H is the tree height.
-------------------------------------------------------
*/

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

pair<int,int> solve(Node* root){

    if(root == NULL){
        return {0,0};
    }

    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);

    pair<int,int> res;

    // Include current node
    res.first = root->data + left.second + right.second;

    // Exclude current node
    res.second = max(left.first, left.second)
               + max(right.first, right.second);

    return res;
}

int getMaxSum(Node* root){

    pair<int,int> ans = solve(root);

    return max(ans.first, ans.second);
}

int main(){

    /*
              1
            /   \
           2     3
          / \   / \
         1   4 5   6

    Include 1:
        1 + 1 + 4 + 5 + 6 = 17

    Exclude 1:
        max(2-subtree) + max(3-subtree)

    Answer = 17
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(1);
    root->left->right = new Node(4);

    root->right->left = new Node(5);
    root->right->right = new Node(6);

    cout << "Maximum Sum = " << getMaxSum(root);

    return 0;
}

/*
-------------------------------------------------------
Mistakes to Avoid
-------------------------------------------------------
1. Don't include children when current node is included.
2. Always return BOTH states (include & exclude).
3. For exclude state, take the maximum from each child.
4. Don't use global variables—the recursion naturally
   returns all required information.
5. Handle NULL nodes by returning {0,0}.

⭐ Interview Tip:
Whenever a tree problem asks you to maximize or minimize
something with restrictions between parent and child,
think of Tree Dynamic Programming (Tree DP).

The two-state DP (include/exclude) is one of the most
important Tree DP patterns.
-------------------------------------------------------
*/