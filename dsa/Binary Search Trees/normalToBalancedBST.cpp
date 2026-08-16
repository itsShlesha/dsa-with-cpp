#include <bits/stdc++.h>
using namespace std;

/*
    PROBLEM STATEMENT:
    - Given a normal BST, convert it into a balanced BST.
    - A balanced BST is a BST where the height difference between
      the left and right subtrees of every node is at most 1.

    APPROACH:
    - Perform inorder traversal of the BST and store all elements
      in a vector.
    - Since inorder traversal of a BST gives elements in sorted order,
      the vector will contain all values in sorted order.
    - Now construct a balanced BST from this sorted vector.
    - Choose the middle element as the root.
    - Recursively construct the left subtree using the left half
      and the right subtree using the right half.
    - Choosing the middle element ensures that both subtrees have
      nearly equal number of nodes.

    WHY IT WORKS:
    - Inorder traversal preserves the sorted order of a BST.
    - Choosing the middle element as root divides the sorted values
      into two nearly equal parts.
    - Repeating this recursively creates a balanced BST.

    TIME COMPLEXITY:
    - Inorder traversal -> O(n)
    - Constructing BST -> O(n)
    - Overall -> O(n)

    SPACE COMPLEXITY:
    - Inorder vector -> O(n)
    - Recursion stack -> O(log n)
    - Overall -> O(n)
*/


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
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

Node* inorderToBST(int s, int e, vector<int>& in){
    if(s > e){
        return NULL;
    }

    int mid = (s + e) / 2;

    Node* root = new Node(in[mid]);

    root->left = inorderToBST(s, mid - 1, in);
    root->right = inorderToBST(mid + 1, e, in);

    return root;
}

Node* balancedBST(Node* root){
    vector<int> inorderVal;

    //storing inorder (sorted values)
    inorder(root, inorderVal);

    return inorderToBST(0, inorderVal.size() - 1, inorderVal);
}

void printInorder(Node* root){
    if(root == NULL){
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main(){

    /*
        Original BST:

                10
               /  \
              8    12
             /      \
            6        14
           /          \
          4            16

        This BST is highly skewed.

        After balancing:

                10
               /  \
              6    14
             / \   / \
            4   8 12 16
    */

    Node* root = new Node(10);

    root->left = new Node(8);
    root->left->left = new Node(6);
    root->left->left->left = new Node(4);

    root->right = new Node(12);
    root->right->right = new Node(14);
    root->right->right->right = new Node(16);

    cout << "Inorder of original BST: ";
    printInorder(root);

    root = balancedBST(root);

    cout << "\nInorder of balanced BST: ";
    printInorder(root);

    return 0;
}

/*
    MISTAKES TO AVOID:
    - In inorderToBST(), the base case must be:
          if(s > e) return NULL;
      because the function returns Node*.
    - Do NOT sort the inorder vector again because inorder traversal
      of a BST is already sorted.
    - Always choose the middle element as the root.
    - Left subtree range:
          s -> mid-1
    - Right subtree range:
          mid+1 -> e

    GOLDEN INTERVIEW TIPS:
    - Whenever you see "convert BST to balanced BST", immediately think:
          BST -> Inorder -> Sorted Array -> Middle Element Recursion
    - The important observation is that a BST's inorder traversal is
      already sorted, so we can rebuild the tree exactly like a
      balanced BST from a sorted array.
    - Choosing the middle element at every step keeps the tree height
      minimum.

    ONE-LINE SUMMARY:
    - Get the sorted elements using inorder traversal, then recursively
      choose the middle element as root to construct the balanced BST.
*/