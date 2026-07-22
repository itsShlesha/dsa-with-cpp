#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
CHECK IF A BINARY TREE IS A SUM TREE
-------------------------------------------------------

Approach:
For every node, compute:
1. Whether its left subtree is a Sum Tree.
2. Whether its right subtree is a Sum Tree.
3. Sum of the current subtree.

A node is a Sum Tree if:
Current Node Value == Left Subtree Sum + Right Subtree Sum

Pair Meaning:
first  -> Is Sum Tree?
second -> Sum of Current Subtree

Time Complexity : O(n)
Space Complexity: O(h)
*/

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

pair<bool,int> isSumTreeFast(node* root){

    // {IsSumTree, SumOfSubtree}

    if(root == NULL){
        return {true,0};
    }

    // Leaf node
    if(root->left == NULL && root->right == NULL){
        return {true, root->data};
    }

    pair<bool,int> isLeftSumTree = isSumTreeFast(root->left);
    pair<bool,int> isRightSumTree = isSumTreeFast(root->right);

    bool leftSum = isLeftSumTree.first;
    bool rightSum = isRightSumTree.first;

    bool condn = (root->data == isLeftSumTree.second + isRightSumTree.second);

    pair<bool,int> ans;

    if(left && right && condn){
        ans.first = true;
        ans.second = root->data + isLeftSumTree.second + isRightSumTree.second;
    }
    else{
        ans.first = false;
        ans.second = 0;
    }

    return ans;
}

bool isSumTree(node* root){
    return isSumTreeFast(root).first;
}

int main(){

    /*
              26
            /    \
          10      3
         /  \      \
        4    6      3

    Sum Tree:
    10 = 4 + 6
    3 = 0 + 3
    26 = 20 + 6

    Output: Tree is a Sum Tree
    */

    node* root = new node(26);

    root->left = new node(10);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(6);

    root->right->right = new node(3);

    if(isSumTree(root))
        cout << "Tree is a Sum Tree";
    else
        cout << "Tree is NOT a Sum Tree";

    return 0;
}

/*
-------------------------------------------------------
IMPORTANT NOTES / COMMON MISTAKES
-------------------------------------------------------

1. NULL tree is always a Sum Tree.

2. A leaf node is always a Sum Tree.
   Its subtree sum is its own value.

3. Pair stores:
   first  -> bool (Is Sum Tree?)
   second -> int (Subtree Sum)

4. Current node satisfies Sum Tree if:
   root->data == leftSum + rightSum

5. If current node is a Sum Tree:
   subtreeSum =
   root->data + leftSum + rightSum
   (or simply 2 * root->data)

6. Don't call isSumTree() inside itself.
   Call the helper function instead.

GOLDEN INTERVIEW TIP:
Whenever a tree problem asks you to verify a property
while also needing subtree information, return both
the property and the subtree value together in a pair.
-------------------------------------------------------
*/