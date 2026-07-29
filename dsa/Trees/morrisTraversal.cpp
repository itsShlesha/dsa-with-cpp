#include <bits/stdc++.h>
using namespace std;

/*
===========================================
MORRIS INORDER TRAVERSAL
Pattern: Threaded Binary Tree
===========================================

PROBLEM
-------
Traverse a binary tree in inorder without
using recursion or an explicit stack.

APPROACH
--------
Maintain a pointer 'curr'.

Case 1:
If curr has no left child,
visit it and move to its right child.

Case 2:
If curr has a left child,
find its inorder predecessor
(rightmost node of left subtree).

If predecessor->right == NULL:
    Create a temporary thread
    predecessor->right = curr
    Move curr to left child

Else:
    Thread already exists
    Remove the thread
    Visit curr
    Move to right child

Every temporary modification is restored before
moving ahead.

TIME COMPLEXITY
---------------
O(N)

SPACE COMPLEXITY
----------------
O(1)
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

vector<int> morrisTraversal(Node* root){
    vector<int> ans;

    Node* curr = root;

    while(curr){

        // If no left child, visit current and move right
        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else{

            // Find inorder predecessor
            Node* pred = curr->left;

            while(pred->right != NULL && pred->right != curr){
                pred = pred->right;
            }

            // Create thread
            if(pred->right == NULL){
                pred->right = curr;
                curr = curr->left;
            }

            // Thread already exists
            else{
                pred->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return ans;
}

int main(){

    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7

    Inorder:
    4 2 5 1 6 3 7
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = morrisTraversal(root);

    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}

/*
===========================================
MISTAKES TO AVOID
===========================================

1. Don't forget to remove the thread:
       pred->right = NULL;

2. Find predecessor correctly:

       while(pred->right != NULL &&
             pred->right != curr)

Otherwise you'll enter an infinite loop.

3. Visit the node only after removing the
   thread when a left subtree exists.

4. If there is no left child,
   visit immediately.

===========================================
INTERVIEW TIPS
===========================================

★ Morris Traversal uses no recursion
  and no stack.

★ It temporarily converts the tree into
  a threaded binary tree.

★ Every edge is visited at most twice,
  giving O(N) time.

★ Tree structure is restored completely.

Remember:

No Left Child
    Visit → Right

Left Child Exists
    No Thread  -> Create Thread -> Left
    Has Thread -> Remove Thread -> Visit -> Right
*/