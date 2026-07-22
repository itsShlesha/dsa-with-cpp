#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
CHECK IF A BINARY TREE IS HEIGHT BALANCED
-------------------------------------------------------

Approach:
For every node, compute:
1. Whether its left subtree is balanced.
2. Whether its right subtree is balanced.
3. Height of its left subtree.
4. Height of its right subtree.

A node is balanced if:
- Left subtree is balanced.
- Right subtree is balanced.
- Difference between their heights is at most 1.

Store both the balance status and height
together using a pair.

Pair Meaning:
first  -> Is Balanced?
second -> Height

Time Complexity : O(n)
Space Complexity: O(h)
*/

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

pair<bool,int> isBalancedFast(Node* root){

    // {IsBalanced, Height}

    if(root == NULL){
        return {true,0};
    }

    pair<bool,int> left = isBalancedFast(root->left);
    pair<bool,int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool,int> ans;

    ans.first = leftAns && rightAns && diff;
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

bool isBalanced(Node* root){
    return isBalancedFast(root).first;
}

int main(){

    /*
            1
          /   \
         2     3
        / \
       4   5

Balanced Tree
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    if(isBalanced(root))
        cout<<"Tree is Balanced";
    else
        cout<<"Tree is NOT Balanced";

    return 0;
}

/*
-------------------------------------------------------
IMPORTANT NOTES / COMMON MISTAKES
-------------------------------------------------------

1. Pair stores:
   first  -> bool (Balanced?)
   second -> int (Height)

2. Don't declare:
   pair<int,int>
   Use:
   pair<bool,int>

3. Compare heights using:
   abs(leftHeight - rightHeight) <= 1

4. Height of current node:
   max(leftHeight, rightHeight) + 1

5. The entire tree is balanced only if:
   Left Balanced &&
   Right Balanced &&
   Height Difference <= 1

6. Compute height and balance together to
   avoid repeated traversals.

GOLDEN INTERVIEW TIP:
Whenever a tree problem asks for both a property
and the height, return them together in a pair.
This reduces an O(n²) solution to O(n).
-------------------------------------------------------
*/