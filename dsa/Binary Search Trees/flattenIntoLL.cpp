#include <bits/stdc++.h>
using namespace std;

/*
=========================================
PROBLEM: Flatten BST into Sorted Linked List
(Morris Traversal)
=========================================

Approach:

1. Perform Morris Inorder Traversal to visit
   nodes in sorted order without recursion
   or an explicit stack.

2. Maintain two pointers:
      head -> first node of linked list
      prev -> previously visited node

3. Whenever a node is visited:
      - If it is the first node,
        make it the head.
      - Otherwise connect:
            prev->right = curr

4. Set every left pointer to NULL.

5. Morris traversal temporarily creates
   threads from the inorder predecessor
   back to the current node and removes
   them after the left subtree is processed.

Why it works:

Morris traversal visits nodes in the exact
same order as recursive inorder traversal.

Since inorder traversal of a BST is sorted,
connecting nodes during each visit naturally
creates a sorted linked list.

Time Complexity:
O(N)

Space Complexity:
O(1)
*/

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* flattenBST(Node* root){
    Node* curr = root;
    Node* head = NULL;
    Node* prev = NULL;

    while(curr != NULL){

        if(curr->left == NULL){

            // Visit current node
            if(prev == NULL){
                head = curr;
            }
            else{
                prev->right = curr;
            }

            curr->left = NULL;
            prev = curr;

            curr = curr->right;
        }
        else{

            Node* pred = curr->left;

            while(pred->right && pred->right != curr){
                pred = pred->right;
            }

            if(pred->right == NULL){

                // Create thread
                pred->right = curr;
                curr = curr->left;
            }
            else{

                // Remove thread
                pred->right = NULL;

                // Visit current node
                if(prev == NULL){
                    head = curr;
                }
                else{
                    prev->right = curr;
                }

                curr->left = NULL;
                prev = curr;

                curr = curr->right;
            }
        }
    }

    if(prev){
        prev->right = NULL;
    }

    return head;
}

void printList(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->right;
    }
}

int main(){

    /*
              4
            /   \
           2     6
          / \   / \
         1   3 5   7
    */

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    Node* head = flattenBST(root);

    printList(head);

    return 0;
}

/*
=========================================
MISTAKES TO AVOID
=========================================

1. Incorrect predecessor condition.

Wrong:
while(pred->right && pred->right != NULL)

Correct:
while(pred->right && pred->right != curr)

Without checking 'curr', you'll never detect
the temporary Morris thread.

-----------------------------------------

2. Forgetting to remove the thread.

Always do:
pred->right = NULL;

Otherwise the tree structure becomes corrupted.

-----------------------------------------

3. Forgetting:
curr->left = NULL;

The final linked list should only use
right pointers.

-----------------------------------------

4. Forgetting to terminate the list.

if(prev)
    prev->right = NULL;

=========================================
INTERVIEW TIP (GOLDEN)
=========================================

There are three common solutions:

1. Inorder + Vector
   Time : O(N)
   Space: O(N)

2. Recursive Inorder
   Time : O(N)
   Space: O(H)

3. Morris Inorder (Optimal)
   Time : O(N)
   Space: O(1)

If an interviewer asks for constant extra
space, Morris Traversal is the expected
optimal solution.
*/