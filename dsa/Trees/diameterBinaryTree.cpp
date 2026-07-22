#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
DIAMETER OF A BINARY TREE (OPTIMIZED)
-------------------------------------------------------

Approach:
For every node, calculate two things together:
1. Diameter of its subtree.
2. Height of its subtree.

Possible diameter at every node:

1. Diameter in left subtree.
2. Diameter in right subtree.
3. Path passing through current node.
   = leftHeight + rightHeight + 1

The answer is the maximum of these three.

Why Pair?
- first  -> Diameter
- second -> Height

Computing both together avoids repeatedly
calculating heights.

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

pair<int,int> diameterFast(node* root){

    // {Diameter, Height}

    if(root == NULL){
        return {0,0};
    }

    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int> ans;

    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(node* root){
    return diameterFast(root).first;
}

int main(){

    /*
             1
           /   \
          2     3
         / \   /
        4   5 6

    Diameter = 5
    (4 -> 2 -> 1 -> 3 -> 6)
    */

    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);

    cout << "Diameter of Tree: " << diameter(root);

    return 0;
}

/*
-------------------------------------------------------
IMPORTANT NOTES / COMMON MISTAKES
-------------------------------------------------------

1. Height and diameter are computed together.

2. Pair stores:
   first  -> Diameter
   second -> Height

3. Height of current node:
   max(leftHeight, rightHeight) + 1

4. Diameter through current node:
   leftHeight + rightHeight + 1

5. Return the pair after updating both values.

6. Brute Force repeatedly computes heights,
   resulting in O(n²).

7. Optimized solution visits each node only once,
   resulting in O(n).

GOLDEN INTERVIEW TIP:
Whenever a tree problem requires multiple values
(e.g., height + diameter, height + balance),
return them together using a pair or a custom class
to avoid redundant traversals.
-------------------------------------------------------
*/