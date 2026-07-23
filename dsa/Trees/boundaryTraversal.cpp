#include <bits/stdc++.h>
using namespace std;

/*
Approach:
Boundary Traversal consists of three parts:

1. Traverse the Left Boundary (excluding leaf nodes).
2. Traverse all Leaf Nodes from left to right.
3. Traverse the Right Boundary (excluding leaf nodes) in reverse order.

The root node is added separately.

Time Complexity: O(N)
Space Complexity: O(H)

Reason:
- Every node is visited at most once.
- Recursive calls use O(H) auxiliary stack space, where H is the height of the tree.
*/

// Binary Tree Node
class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Traverse Left Boundary (excluding leaf nodes)
void traverseLeft(Node* root, vector<int>& ans){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }

    ans.push_back(root->data);

    if(root->left){
        traverseLeft(root->left, ans);
    }
    else{
        traverseLeft(root->right, ans);
    }
}

// Traverse all Leaf Nodes
void traverseLeaves(Node* root, vector<int>& ans){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }

    traverseLeaves(root->left, ans);
    traverseLeaves(root->right, ans);
}

// Traverse Right Boundary (excluding leaf nodes)
void traverseRight(Node* root, vector<int>& ans){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }

    if(root->right){
        traverseRight(root->right, ans);
    }
    else{
        traverseRight(root->left, ans);
    }

    // Add while returning so that order becomes bottom-up
    ans.push_back(root->data);
}

// Boundary Traversal
vector<int> boundary(Node* root){

    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    ans.push_back(root->data);

    traverseLeft(root->left, ans);

    traverseLeaves(root->left, ans);
    traverseLeaves(root->right, ans);

    traverseRight(root->right, ans);

    return ans;
}

int main(){

    /*
                1
             /     \
            2       3
           / \     / \
          4   5   6   7
             / \
            8   9

    Boundary:
    1 2 4 8 9 6 7 3
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = boundary(root);

    cout << "Boundary Traversal : ";

    for(int x : ans){
        cout << x << " ";
    }

    cout << endl;

    return 0;
}

/*
Mistakes to Avoid:

1. Do NOT include leaf nodes while traversing left and right boundaries.
   They are added separately during leaf traversal.

2. Add right boundary nodes AFTER recursive calls.
   This automatically gives bottom-up order.

3. Don't forget to traverse leaves of BOTH left and right subtrees.

4. Root should be added only once.

⭐ Interview Tip:
Think of Boundary Traversal as:
Root
→ Left Boundary
→ Leaves
→ Right Boundary (Reverse)

Breaking the problem into these three independent traversals makes the implementation much simpler and avoids duplicate nodes.
*/