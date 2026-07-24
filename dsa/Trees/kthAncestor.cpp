#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: K-th Ancestor of a Node in a Binary Tree
-------------------------------------------------------
Approach:
1. Perform a DFS traversal to locate the target node.
2. Once found, return the target node upwards through
   recursive calls.
3. While backtracking, decrement K at each ancestor.
4. When K becomes 0, the current node is the K-th ancestor.
5. Set K to INT_MAX to prevent further updates while
   unwinding the recursion.
6. If K ancestors do not exist, return -1.

Time Complexity : O(N)
Space Complexity: O(H)
where H is the height of the tree.
-------------------------------------------------------
*/

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* solve(Node* root, int &k, int node){

    if(root == NULL)
        return NULL;

    if(root->data == node)
        return root;

    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);

    if(leftAns != NULL && rightAns == NULL){

        k--;

        if(k <= 0){
            k = INT_MAX;
            return root;
        }

        return leftAns;
    }

    if(leftAns == NULL && rightAns != NULL){

        k--;

        if(k <= 0){
            k = INT_MAX;
            return root;
        }

        return rightAns;
    }

    return NULL;
}

int kthAncestor(Node* root, int k, int node){

    Node* ans = solve(root, k, node);

    if(ans == NULL || ans->data == node) 
        return -1;

    if(ans->data == node)
        return -1;

    return ans->data;
}

int main(){

    /*
               1
             /   \
            2     3
           / \   / \
          4   5 6   7
             /
            8

    1st ancestor of 8 = 5
    2nd ancestor of 8 = 2
    3rd ancestor of 8 = 1
    4th ancestor of 8 = -1
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->right->left = new Node(8);

    cout << "1st Ancestor : " << kthAncestor(root,1,8) << endl;
    cout << "2nd Ancestor : " << kthAncestor(root,2,8) << endl;
    cout << "3rd Ancestor : " << kthAncestor(root,3,8) << endl;
    cout << "4th Ancestor : " << kthAncestor(root,4,8) << endl;

    return 0;
}

/*
-------------------------------------------------------
Mistakes to Avoid
-------------------------------------------------------
1. Forgetting to decrement K during backtracking.
2. Updating the answer multiple times after finding the
   ancestor (use K = INT_MAX).
3. Missing the case where the target itself is returned
   (ancestor doesn't exist).
4. Forgetting to return NULL when neither subtree
   contains the target.
5. Passing K by value instead of reference.

⭐ Interview Tip:
This is a classic DFS backtracking problem.
The recursion first finds the node, then uses the
recursive return path to count ancestors without
storing the entire path explicitly.
-------------------------------------------------------
*/