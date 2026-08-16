#include <bits/stdc++.h>
using namespace std;

/*
***************************************
    SEARCH IN A BINARY SEARCH TREE
***************************************

Problem Statement:
Given the root of a Binary Search Tree (BST) and a target value,
determine whether the target exists in the tree.

Approach:
1. Start from the root node.
2. Compare the current node's value with the target.
3. If they are equal, return true.
4. If the target is smaller, move to the left child.
5. Otherwise, move to the right child.
6. Continue until either the target is found or the current
   node becomes NULL.

Why this works:
A BST satisfies the property:

Left Subtree < Root < Right Subtree

At every comparison, one entire subtree can be discarded,
reducing the search space just like Binary Search on an array.

Time Complexity:
Worst Case : O(H)
H = Height of the tree

Balanced BST : O(log N)
Skewed BST   : O(N)

Space Complexity:
O(1)

Since we use iteration instead of recursion,
no extra stack space is required.
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

bool searchNode(Node* root, int x){
    /*
    // Base Case
    if(root == NULL){
        return false;
    }

    // Element Found
    if(root->data == x){
        return true;
    }

    // Search in Left Subtree
    if(root->data > x){
        return searchNode(root->left, x);
    }

    // Search in Right Subtree
    return searchNode(root->right, x);
    */

    Node* temp = root;

    while(temp != NULL){
        if(temp->data == x){
            return true;
        }
        if(temp->data > x){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}

int main() {

    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);

    root->left->left = new Node(1);
    root->left->right = new Node(6);

    root->right->right = new Node(14);

    int target = 6;

    if(searchNode(root, target))
        cout << "Element Found";
    else
        cout << "Element Not Found";

    return 0;
}

/*
***************************************
        MISTAKES TO AVOID
***************************************

1. Don't traverse both left and right subtrees.
   BST allows searching in only one direction.

2. Remember:
   if(target < current->data)
       move LEFT;
   else
       move RIGHT;

3. Always update the current pointer,
   otherwise the loop becomes infinite.

4. Stop immediately after finding the target.

5. Don't forget to return false if the traversal
   reaches NULL.

***************************************
        GOLDEN INTERVIEW TIPS
***************************************

★ This is Binary Search applied to a BST.

★ Every comparison eliminates one entire subtree.

★ Iterative traversal is preferred in interviews because
  it uses O(1) auxiliary space.

★ Recursive and iterative solutions have the same
  time complexity, but iteration avoids recursion overhead.

Pattern:
Start at Root → Compare → Move Left/Right → Repeat until
Found or NULL.
*/