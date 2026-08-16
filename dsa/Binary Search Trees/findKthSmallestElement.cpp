#include <bits/stdc++.h>
using namespace std;

/*
*********************************************
      KTH SMALLEST ELEMENT IN A BST
        (MORRIS TRAVERSAL)
*********************************************

Problem Statement:
Given the root of a Binary Search Tree and an
integer k, return the kth smallest element.

Approach:
1. Perform Morris Inorder Traversal, which visits
   the BST in sorted order without using recursion
   or an explicit stack.

2. For every current node:
   • If there is no left child:
        - Visit the node.
        - Increment the counter.
        - Move to the right child.

   • Otherwise:
        - Find the inorder predecessor
          (rightmost node of the left subtree).

        - If a thread does not exist:
              Create a temporary thread from the
              predecessor to the current node and
              move to the left subtree.

        - If a thread already exists:
              Remove the thread.
              Visit the current node.
              Increment the counter.
              Move to the right subtree.

3. When the counter becomes equal to k,
   return the current node's value.

Why this works:
Morris Traversal performs an inorder traversal by
temporarily creating links (threads) back to a node
after finishing its left subtree.

Since inorder traversal of a BST is always sorted,
the kth visited node is the kth smallest element.

Time Complexity:
O(N)

Every edge is traversed at most twice.

Space Complexity:
O(1)

No recursion or stack is used.
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

/*
int solve(Node* root, int& i, int k){

    if(root == NULL){
        return -1;
    }

    int left = solve(root->left, i, k);

    if(left != -1){
        return left;
    }

    i++;

    if(i == k){
        return root->data;
    }

    return solve(root->right, i, k);
}
*/

int kthSmallest(Node* root, int k){
/*
    int i = 0;

    return solve(root, i, k);

*/

    Node* curr = root;
    int count = 0;

    while(curr){
        if(curr->left == NULL){
            count++;

            if(count == k)
                return curr->data;

            curr = curr->right;
        }
        else{
            Node* pred = curr->left;

            while(pred->right && pred->right != curr)
                pred = pred->right;

            if(pred->right == NULL){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                pred->right = NULL;

                count++;
                if(count == k){
                    return curr->data;
                }

                curr = curr->right;
            }
        }
    }

    return -1;
}

void inorder(Node* root){

    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){

    /*
              5
            /   \
           3     7
          / \   / \
         2  4  6   8
    */

    Node* root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(7);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->right->left = new Node(6);
    root->right->right = new Node(8);

    int k = 3;

    cout << "Kth Smallest Element: " << kthSmallest(root, k);

    return 0;
}

/*
*********************************************
            MISTAKES TO AVOID
*********************************************

1. Always remove the temporary thread after
   returning from the left subtree.

2. Don't visit a node before its left subtree
   has been completely processed.

3. Visit the node only:
   • When left child is NULL, or
   • After removing the temporary thread.

4. Don't forget to increment the counter only
   when the node is actually visited.

5. Never leave the BST modified after traversal.
   Every created thread must be removed.

*********************************************
          GOLDEN INTERVIEW TIPS
*********************************************

★ Morris Traversal performs inorder traversal
  using O(1) extra space.

★ Inorder traversal of a BST always produces
  elements in sorted order.

★ The inorder predecessor is the rightmost node
  of the left subtree.

★ Every temporary thread is created exactly once
  and removed exactly once.

Memory Trick:

No Left Child
    ↓
Visit → Right

Left Child Exists
    ↓
Find Predecessor
    ↓
Thread Missing?
    ↓
Create Thread → Left

Thread Exists?
    ↓
Remove Thread
Visit
Right
*/