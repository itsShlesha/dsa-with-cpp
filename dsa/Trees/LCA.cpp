#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: Lowest Common Ancestor in a Binary Tree
-------------------------------------------------------
Approach:
1. Traverse the tree using DFS.
2. Base Cases:
      • If current node is NULL, return NULL.
      • If current node matches either target node,
        return the current node.
3. Recursively search left and right subtrees.
4. Cases:
      • Both sides return non-NULL:
            Current node is the LCA.
      • Only left returns non-NULL:
            Return left result.
      • Only right returns non-NULL:
            Return right result.
      • Both NULL:
            Return NULL.

Time Complexity : O(N)
Space Complexity: O(H)
where H is the height of the tree.
-------------------------------------------------------
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

Node* lca(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftAns = lca(root->left, n1, n2);
    Node* rightAns = lca(root->right, n1, n2);

    if(leftAns != NULL && rightAns != NULL){
        return root;
    }
    else if(leftAns != NULL){
        return leftAns;
    }
    else if(rightAns != NULL){
        return rightAns;
    }

    return NULL;
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

    LCA(4,8) = 2
    LCA(6,7) = 3
    LCA(4,7) = 1
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->right->left = new Node(8);

    cout << "LCA of 4 and 8 : "
         << lca(root,4,8)->data << endl;

    cout << "LCA of 6 and 7 : "
         << lca(root,6,7)->data << endl;

    cout << "LCA of 4 and 7 : "
         << lca(root,4,7)->data << endl;

    return 0;
}

/*
-------------------------------------------------------
Mistakes to Avoid
-------------------------------------------------------
1. Forgetting the base case when current node matches
   either target node.
2. Returning the current node even if only one subtree
   contains a target.
3. Confusing Binary Tree LCA with BST LCA.
4. Traversing the entire tree after LCA is already found.
5. Not handling NULL pointers properly.

⭐ Interview Tip:
This recursion works because each subtree reports
whether it contains either target node. The first node
that receives one target from each side is the Lowest
Common Ancestor.
-------------------------------------------------------
*/