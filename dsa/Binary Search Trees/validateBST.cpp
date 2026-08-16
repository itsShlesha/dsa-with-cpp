#include <bits/stdc++.h>
using namespace std;

/*
*********************************************
        VALIDATE A BINARY SEARCH TREE
*********************************************

Problem Statement:
Given the root of a Binary Tree, determine whether
it satisfies the Binary Search Tree (BST) property.

Approach:
Use a valid range for every node.

Initially:
(-∞, +∞)

For every node:
1. The node's value must lie within its valid range.
2. For the left subtree:
      Maximum allowed value becomes current node.
3. For the right subtree:
      Minimum allowed value becomes current node.
4. Recursively validate both subtrees.

Why this works:
Every node in a BST is constrained not only by its
parent, but by all of its ancestors.

Passing the valid range ensures every node satisfies
all ancestor constraints.

Time Complexity:
O(N)

Every node is visited exactly once.

Space Complexity:
O(H)

Recursive stack space.

Balanced BST : O(log N)
Worst Case   : O(N)
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

bool isBST(Node* root, long long minVal, long long maxVal){

    if(root == NULL)
        return true;

    if(root->data > minVal && root->data < maxVal){

        bool left = isBST(root->left, minVal, root->data);

        bool right = isBST(root->right, root->data, maxVal);

        return left && right;
    }

    return false;
}

bool validateBST(Node* root){
    return isBST(root, LLONG_MIN, LLONG_MAX);
}

int main(){

    /*
            8
          /   \
         3     10
        / \      \
       1   6      14
          / \    /
         4   7  13
    */

    Node* root = new Node(8);

    root->left = new Node(3);
    root->right = new Node(10);

    root->left->left = new Node(1);
    root->left->right = new Node(6);

    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    if(validateBST(root))
        cout << "Valid BST";
    else
        cout << "Not a BST";

    return 0;
}

/*
*********************************************
            MISTAKES TO AVOID
*********************************************

1. Don't compare only with the parent node.

2. Every node must satisfy the constraints imposed
   by all its ancestors.

3. Use strict inequalities:
   value > min
   value < max

4. Use LLONG_MIN and LLONG_MAX instead of INT_MIN
   and INT_MAX to avoid overflow edge cases.

5. Always update the range while making recursive
   calls.

*********************************************
          GOLDEN INTERVIEW TIPS
*********************************************

★ This is the most common BST validation approach.

★ Think of every node carrying a valid interval.

★ Left subtree:
   (min, root->data)

★ Right subtree:
   (root->data, max)

★ Range Validation is more reliable than simply
  checking parent-child relationships.

Memory Trick:

Every node asks:
"Am I inside my allowed range?"
*/