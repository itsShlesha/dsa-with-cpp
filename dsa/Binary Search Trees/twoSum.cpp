#include <bits/stdc++.h>
using namespace std;

/*
=========================================
PROBLEM: Two Sum in BST
=========================================

Approach:
1. Perform an inorder traversal of the BST.
2. Since inorder traversal of a BST is always sorted,
   store all node values inside a vector.
3. Apply the classic Two Pointer approach:
      left = 0
      right = n-1

4. If current sum equals target -> answer found.
5. If sum is too large -> move right pointer left.
6. Otherwise move left pointer right.

Why it works:
BST inorder traversal gives sorted order.
Two pointers efficiently search a sorted array
for a target sum in linear time.

Time Complexity:
O(N)

Space Complexity:
O(N)
(Inorder vector)
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

void inorder(Node* root, vector<int>& in){
    if(root == NULL){
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

bool twoSumBST(Node* root, int target){
    vector<int> inorderTraversal;

    inorder(root, inorderTraversal);

    int i = 0, j = inorderTraversal.size() - 1;

    while(i < j){
        int sum = inorderTraversal[i] + inorderTraversal[j];

        if(sum == target){
            return true;
        }
        else if(sum > target){
            j--;
        }
        else{
            i++;
        }
    }

    return false;
}

int main() {
    /*
             8
           /   \
          5     10
         / \      \
        2   6      11
    */

    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->right = new Node(11);

    int target = 16;

    if (twoSumBST(root, target))
        cout << "Pair exists\n";
    else
        cout << "Pair does not exist\n";

    return 0;
}

/*
=========================================
MISTAKES TO AVOID
=========================================

1. Forgetting that inorder of BST is sorted.
2. Declaring pointers incorrectly:
      int i = 0, j = n-1;
3. Using <= instead of < in the while loop.
4. Forgetting to pass vector by reference.
5. Accidentally modifying the BST.

=========================================
INTERVIEW TIP (GOLDEN)
=========================================

This solution is optimal only if O(N) extra
space is allowed.

If the interviewer asks for O(H) space,
use two BST iterators:
- One inorder iterator
- One reverse inorder iterator

That gives:

Time  : O(N)
Space : O(H)

This is the follow-up expected in interviews.
*/