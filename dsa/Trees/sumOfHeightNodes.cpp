#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: Sum of the Longest Bloodline of a Tree
-------------------------------------------------------
Approach:
1. Perform a DFS traversal.
2. Maintain:
      - Current path length.
      - Current path sum.
3. Whenever a NULL node is reached:
      • If current path is longer than previous longest,
        update both maximum length and maximum sum.
      • If lengths are equal, keep the larger sum.
4. Continue recursively for both left and right subtrees.

Time Complexity : O(N)
Space Complexity: O(H)
where H is the height of the tree (recursion stack).
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

void solve(Node* root, int sum, int &maxSum, int len, int &maxLen){
    if(root == NULL){
        if(len > maxLen){
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen){
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum += root->data;

    solve(root->left, sum, maxSum, len + 1, maxLen);
    solve(root->right, sum, maxSum, len + 1, maxLen);
}

int sumOfLongestBloodlineInTree(Node* root){
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = INT_MIN;

    solve(root, sum, maxSum, len, maxLen);

    return maxSum;
}

int main(){

    /*
            1
          /   \
         2     3
        / \     \
       4   5     6
      /
     7

    Longest Bloodline:
    1 -> 2 -> 4 -> 7

    Sum = 14
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(6);

    root->left->left->left = new Node(7);

    cout << "Sum of Longest Bloodline = "
         << sumOfLongestBloodlineInTree(root);

    return 0;
}

/*
-------------------------------------------------------
Mistakes to Avoid
-------------------------------------------------------
1. Increment path length by only +1 for every recursive call.
2. When lengths are equal, update maxSum instead of maxLen.
3. Update answer only at the leaf boundary (NULL after traversal).
4. Pass maxLen and maxSum by reference.
5. Don't forget to add the current node's value before recursion.

⭐ Interview Tip:
This is a classic DFS + backtracking pattern where
multiple path properties (length & sum) are tracked
simultaneously. Similar questions often ask you to
maximize/minimize another property while traversing.
-------------------------------------------------------
*/