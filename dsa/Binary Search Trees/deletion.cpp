#include <bits/stdc++.h>
using namespace std;

/*
*********************************************
          DELETE A NODE IN A BST
*********************************************

Problem Statement:
Given the root of a Binary Search Tree and a value,
delete the node containing that value while preserving
the BST property.

Approach:
1. Search for the node to be deleted.
2. Once found, handle four cases:

   Case 1:
   Node has no children.
   -> Delete it and return NULL.

   Case 2:
   Node has only a left child.
   -> Return the left child.

   Case 3:
   Node has only a right child.
   -> Return the right child.

   Case 4:
   Node has two children.
   -> Find the inorder successor
      (minimum node in the right subtree).
   -> Copy its value into the current node.
   -> Delete the successor recursively from the
      right subtree.

Why this works:
For nodes with two children, replacing the node
with its inorder successor preserves the BST order.

The recursive calls reconnect the modified subtree
back to its parent automatically.

Time Complexity:
O(H)

H = Height of the BST

Balanced BST : O(log N)
Skewed BST   : O(N)

Space Complexity:
O(H)

Recursive call stack.

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

// Returns the leftmost node (minimum) in a subtree
Node* findSuccessor(Node* root){
    Node* temp = root;

    while(temp->left)
        temp = temp->left;

    return temp;
}

Node* deleteFromBST(Node* root, int val){

    if(root == NULL){
        return root;
    }

    if(root->data == val){

        // Case 1 : No Child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // Case 2 : One Left Child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3 : One Right Child
        if(root->right != NULL && root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 4 : Two Children
        if(root->left != NULL && root->right != NULL){

            Node* successor = findSuccessor(root->right);

            root->data = successor->data;

            root->right = deleteFromBST(root->right, successor->data);

            return root;
        }
    }

    else if(root->data > val){
        root->left = deleteFromBST(root->left, val);
    }

    else{
        root->right = deleteFromBST(root->right, val);
    }

    return root;
}

int main() {

    /*
                50
              /    \
            30      70
           / \     / \
         20  40   60  80
    */

    Node* root = new Node(50);

    root->left = new Node(30);
    root->right = new Node(70);

    root->left->left = new Node(20);
    root->left->right = new Node(40);

    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int val = 50;

    root = deleteFromBST(root, val);

    cout << "Inorder Traversal after Deletion: ";

    function<void(Node*)> inorder = [&](Node* root){
        if(root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    };

    inorder(root);

    return 0;
}

/*
*********************************************
            MISTAKES TO AVOID
*********************************************

1. Always return the updated subtree after deletion.

2. Don't forget to reconnect:
   root->left = delete(...)
   root->right = delete(...)

3. For two children, don't delete the current node
   directly.

4. Replace the current node's value with the inorder
   successor (or predecessor), then delete that node.

5. Inorder Successor:
   Right subtree -> Leftmost node.

6. Remember to delete the removed node to avoid
   memory leaks.

*********************************************
          GOLDEN INTERVIEW TIPS
*********************************************

★ Deletion is the most important BST operation.

★ The difficult case is when the node has two children.

★ Inorder Successor is the smallest element in the
  right subtree.

★ Some implementations use the inorder predecessor
  instead. Both approaches are correct.

Memory Trick:

0 Child  -> Delete.

1 Child  -> Replace with child.

2 Children ->
Successor -> Copy -> Delete Successor.
*/