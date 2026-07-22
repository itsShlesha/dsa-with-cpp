#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
COUNT LEAF NODES IN A BINARY TREE
-------------------------------------------------------

Approach:
1. Perform an Inorder Traversal (Left -> Root -> Right).
2. For every visited node:
   - If both left and right child are NULL,
     it is a leaf node.
   - Increment the count.
3. Return the final count after traversal.

Why Inorder?
- A leaf node can be identified in any traversal
  (Inorder, Preorder, or Postorder).
- Inorder is used here simply to visit every node once.

Time Complexity : O(n)
Space Complexity: O(h)
where h is the height of the tree (recursive stack).
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

void inorder(node* root, int &count){
    // Base Case
    if(root == NULL){
        return;
    }

    // Left Subtree
    inorder(root->left, count);

    // Check if current node is a leaf node
    if(root->left == NULL && root->right == NULL){
        count++;
    }

    // Right Subtree
    inorder(root->right, count);
}

int noOfLeafNodes(node* root){
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}

int main(){
    /*
            1
          /   \
         2     3
        / \     \
       4   5     6

    Leaf Nodes = 4, 5, 6
    */

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);

    cout << "Number of Leaf Nodes: " << noOfLeafNodes(root);

    return 0;
}

/*
-------------------------------------------------------
IMPORTANT NOTES / COMMON MISTAKES
-------------------------------------------------------

1. A leaf node has BOTH children as NULL.
   Condition:
   root->left == NULL && root->right == NULL

2. Pass the count variable by reference (&count),
   otherwise updates won't reflect in recursive calls.

3. Always check the base case first:
   if(root == NULL) return;

4. Every node is visited exactly once,
   making the solution linear.

5. This problem can be solved using any DFS traversal
   (Preorder, Inorder, or Postorder).

GOLDEN INTERVIEW TIP:
Whenever asked to count nodes satisfying a condition,
perform a DFS traversal and update the answer whenever
the condition becomes true.
-------------------------------------------------------
*/