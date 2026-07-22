#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
HEIGHT OF A BINARY TREE
-------------------------------------------------------

Approach:
1. If the tree is empty, height = 0.
2. Recursively calculate:
   - Height of left subtree.
   - Height of right subtree.
3. Height of current node =
      max(leftHeight, rightHeight) + 1
4. Return the computed height.

Why Recursion?
- Height of a node depends on the heights of
  its left and right subtrees.
- Recursion naturally solves this bottom-up.

Time Complexity : O(n)
Space Complexity: O(h)
where h is the height of the tree.
*/

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

int height(node* root){
    // Base Case
    if(root == NULL){
        return 0;
    }

    // Height of left subtree
    int left = height(root->left);

    // Height of right subtree
    int right = height(root->right);

    // Current node's height
    return max(left, right) + 1;
}

int main(){

    /*
             1
           /   \
          2     3
         / \   /
        4   5 6

Height = 3
    */

    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);

    cout << "Height of Tree: " << height(root);

    return 0;
}

/*
-------------------------------------------------------
IMPORTANT NOTES / COMMON MISTAKES
-------------------------------------------------------

1. Use 'root', not the class name 'node'.
   Correct:
      height(root->left)
   Incorrect:
      height(node->left)

2. Base case:
   An empty tree has height = 0.

3. Add 1 for the current node after finding
   the maximum height of its subtrees.

4. Every node is visited exactly once,
   resulting in O(n) time complexity.

5. Recursive stack space depends on the
   height of the tree.

GOLDEN INTERVIEW TIP:
Whenever a tree problem asks for the longest path
from a node to a leaf, think of recursively finding
the answer from the left and right subtrees and
combining them using max().
-------------------------------------------------------
*/