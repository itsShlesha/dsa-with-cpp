#include <bits/stdc++.h>
using namespace std;

/*
===========================================
FLATTEN BINARY TREE TO LINKED LIST
Pattern: Morris Traversal Modification
===========================================

PROBLEM
-------
Flatten a binary tree into a linked list
in-place following preorder traversal.

Every node's:
    left  -> NULL
    right -> next node in preorder

APPROACH
--------
Traverse the tree using a pointer 'curr'.

For every node:

1. If no left child exists,
   simply move to the right child.

2. Otherwise:

   • Find the rightmost node of the
     left subtree (preorder predecessor).

   • Attach the current node's original
     right subtree to predecessor->right.

   • Move the left subtree to the right.

   • Set left pointer to NULL.

Continue moving along the right pointers
until traversal finishes.

This rewires the tree in-place without
using recursion or an explicit stack.

TIME COMPLEXITY
---------------
O(N)

Each node is processed at most once.

SPACE COMPLEXITY
----------------
O(1)

No recursion.
No stack.
Only pointer manipulation.
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

void flatten(Node* root){

    Node* curr = root;

    while(curr != NULL){

        if(curr->left){

            // Find predecessor (rightmost node of left subtree)
            Node* pred = curr->left;

            while(pred->right){
                pred = pred->right;
            }

            // Attach original right subtree
            pred->right = curr->right;

            // Move left subtree to right
            curr->right = curr->left;
            curr->left = NULL;
        }

        curr = curr->right;
    }
}

void printLinkedList(Node* root){

    while(root){
        cout << root->data << " ";
        root = root->right;
    }

    cout << endl;
}

int main(){

    /*
              1
            /   \
           2     5
          / \     \
         3   4     6

    Flattened:
    1 -> 2 -> 3 -> 4 -> 5 -> 6
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(5);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->right = new Node(6);

    flatten(root);

    cout << "Flattened Linked List: ";
    printLinkedList(root);

    return 0;
}

/*
===========================================
MISTAKES TO AVOID
===========================================

1. Loop condition should be

       while(curr != NULL)

   NOT

       while(curr != root)

2. Always find the rightmost node
   of the left subtree before rewiring.

3. Attach the original right subtree first:

       pred->right = curr->right;

   Otherwise the right subtree is lost.

4. Move left subtree to right:

       curr->right = curr->left;

5. Finally set

       curr->left = NULL;

6. Move only through right pointers
   after every modification.

===========================================
INTERVIEW TIPS
===========================================

★ This is a Morris Traversal variation.

★ No extra data structures are required.

★ The final linked list follows
   preorder traversal:
       Root -> Left -> Right

★ Unlike Morris Inorder Traversal,
  no temporary threads are created.
  The tree is permanently rewired.

Pattern Recognition:

If asked to flatten a tree in-place
using O(1) extra space,
think of this predecessor-rewiring approach.
*/