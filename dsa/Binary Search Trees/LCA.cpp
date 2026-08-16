#include <bits/stdc++.h>
using namespace std;

/*
*********************************************
     LOWEST COMMON ANCESTOR IN A BST
        (ITERATIVE APPROACH)
*********************************************

Problem Statement:
Given the root of a Binary Search Tree and two
nodes p and q, return their Lowest Common Ancestor.

Lowest Common Ancestor (LCA):
The lowest node in the tree that has both p and q
as descendants (a node can be a descendant of itself).

Approach:
Use the BST property to iteratively move towards
the Lowest Common Ancestor.

1. Start from the root.

2. If both p and q are greater than the current
   node, move to the right subtree.

3. If both p and q are smaller than the current
   node, move to the left subtree.

4. Otherwise, the current node is the split point
   where one node lies on each side (or one node
   is the current node itself).

5. Return the current node.

Why this works:
A BST stores smaller values in the left subtree
and larger values in the right subtree.

If both nodes lie on the same side, the LCA must
also lie on that side.

The first node where their paths diverge is
their Lowest Common Ancestor.

Time Complexity:
O(H)

H = Height of the BST

Balanced BST : O(log N)
Skewed BST   : O(N)

Space Complexity:
O(1)

No recursion or auxiliary data structures are used.
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

Node* LCA(Node* root, Node* p, Node* q){
/*
    if(root == NULL){
        return NULL;
    }

    // Both nodes lie in the right subtree
    if(root->data < p->data && root->data < q->data){
        return LCA(root->right, p, q);
    }

    // Both nodes lie in the left subtree
    if(root->data > p->data && root->data > q->data){
        return LCA(root->left, p, q);
    }

    // Split point found
    return root;

*/

    if(root = NULL)
        return NULL;

    while(root != NULL){
        if(root->data < p->data && root->data < q->data){
            root = root->right;
        }
        else if(root->data > p->data && root->data > q->data){
            root = root->left;
        }
        else{
            return root;
        }
    }

    return NULL;
}

int main(){

    /*
                20
              /    \
            10      30
           /  \    /  \
          5   15  25  35
    */

    Node* root = new Node(20);

    root->left = new Node(10);
    root->right = new Node(30);

    root->left->left = new Node(5);
    root->left->right = new Node(15);

    root->right->left = new Node(25);
    root->right->right = new Node(35);

    Node* p = root->left->left;      // 5
    Node* q = root->left->right;     // 15

    Node* ans = LCA(root, p, q);

    cout << "LCA: " << ans->data;

    return 0;
}

/*
*********************************************
            MISTAKES TO AVOID
*********************************************

1. Don't solve this like a normal Binary Tree.
   Use the BST property.

2. Remember the three cases:

   Both Left  -> Move Left

   Both Right -> Move Right

   Split Point -> Current Node is LCA

3. If one node is equal to the current node,
   the current node itself is the LCA.

4. Use '==' while checking for NULL.

   Correct:
   if(root == NULL)

   Wrong:
   if(root = NULL)

5. Return NULL after the loop to avoid compiler
   warnings.

*********************************************
          GOLDEN INTERVIEW TIPS
*********************************************

★ This is one of the few tree problems that can
  be solved without recursion.

★ The iterative solution is preferred because it
  uses O(1) auxiliary space.

★ Unlike Binary Tree LCA (O(N)),
  BST LCA works in O(H) by eliminating one
  subtree at every step.

Memory Trick:

Current Node

↓

Both Left?
    ↓
 Move Left

Both Right?
    ↓
 Move Right

Otherwise
    ↓
Current Node = LCA
*/