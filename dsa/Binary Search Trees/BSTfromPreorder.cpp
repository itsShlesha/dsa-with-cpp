#include <bits/stdc++.h>
using namespace std;

/*
    PROBLEM STATEMENT:
    - Given a preorder traversal of a BST, construct the original BST.
    - The preorder traversal follows:
          Root -> Left -> Right
    - We need to use this order to reconstruct the BST without explicitly
      sorting the elements.

    APPROACH:
    - Use recursion with a valid range [mini, maxi] for every node.
    - The current preorder element can become the root only if it lies
      inside this valid range.
    - Create the root using preorder[i] and increment i.
    - For the left subtree, values must be smaller than root->data:
          [mini, root->data]
    - For the right subtree, values must be greater than root->data:
          [root->data, maxi]
    - Since preorder gives Root -> Left -> Right, after creating a node,
      the next valid elements naturally belong to its left subtree first,
      followed by its right subtree.
    - If the current element falls outside the allowed range, simply
      return NULL without incrementing i so that the same element can
      be considered by the parent/right subtree.

    WHY IT WORKS:
    - BST property tells us exactly which values are allowed in the
      left and right subtrees.
    - The range keeps track of these restrictions while preorder
      determines the order in which nodes must be created.
    - Therefore, every element gets placed at its correct position.

    TIME COMPLEXITY:
    - Each element is processed once -> O(n)

    SPACE COMPLEXITY:
    - Recursion stack -> O(h)
    - Worst case -> O(n)
    - Average/balanced BST -> O(log n)
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

Node* solve(vector<int>& preorder, int mini, int maxi, int &i){
    if(i >= preorder.size()){
        return NULL;
    }

    if(preorder[i] < mini || preorder[i] > maxi){
        return NULL;
    }

    Node* root = new Node(preorder[i++]);

    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);

    return root;
}

Node* preorderToBST(vector<int>& preorder){
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;

    return solve(preorder, mini, maxi, i);
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){

    vector<int> preorder = {10, 5, 1, 7, 40, 50};

    Node* root = preorderToBST(preorder);

    cout << "Inorder traversal of constructed BST: ";
    inorder(root);

    return 0;
}

/*
    MISTAKES TO AVOID:
    - The base case must be:
          if(i >= preorder.size()) return NULL;
      NOT:
          if(i > preorder.size())
      because the last valid index is size-1.
    - Do NOT increment i when preorder[i] is outside the current range.
    - Remember the preorder order:
          Root -> Left -> Right
    - Left subtree gets:
          [mini, root->data]
    - Right subtree gets:
          [root->data, maxi]

    GOLDEN INTERVIEW TIPS:
    - Whenever you see "construct BST from preorder", think:
          Preorder + Range Limits
    - No sorting is required.
    - The key idea is that every subtree has a valid range, and preorder
      tells us which node comes next.
    - Passing i by reference is important because both recursive calls
      must work on the same preorder position.

    ONE-LINE SUMMARY:
    - Use preorder order to create nodes and maintain a valid [mini,maxi]
      range to decide whether each element belongs to the current subtree.
*/