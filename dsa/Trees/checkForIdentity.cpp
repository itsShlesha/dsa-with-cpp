#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
CHECK IF TWO BINARY TREES ARE IDENTICAL
-------------------------------------------------------

Approach:
1. If both nodes are NULL,
   the trees are identical up to this point.

2. If only one node is NULL,
   the trees are different.

3. Recursively compare:
   - Left subtrees.
   - Right subtrees.
   - Current node values.

4. Trees are identical only if all three
   comparisons return true.

Time Complexity : O(n)
Space Complexity: O(h)
where h is the height of the tree.
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

bool isIdentical(node* r1, node* r2){

    // Both trees are empty
    if(r1 == NULL && r2 == NULL)
        return true;

    // One tree is empty
    if(r1 == NULL || r2 == NULL)
        return false;

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool value = (r1->data == r2->data);

    return left && right && value;
}

int main(){

    /*
            Tree 1             Tree 2

               1                  1
             /   \              /   \
            2     3            2     3
           /                  /
          4                  4
    */

    node* root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left = new node(4);

    node* root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);
    root2->left->left = new node(4);

    if(isIdentical(root1, root2))
        cout << "Trees are Identical";
    else
        cout << "Trees are NOT Identical";

    return 0;
}

/*
-------------------------------------------------------
IMPORTANT NOTES / COMMON MISTAKES
-------------------------------------------------------

1. Two NULL nodes are considered identical.

2. If one node is NULL and the other isn't,
   immediately return false.

3. Compare:
   - Left subtree
   - Right subtree
   - Current node value

4. Every corresponding node in both trees
   must have the same value and structure.

5. The recursion stops as soon as a mismatch
   is found.

GOLDEN INTERVIEW TIP:
Whenever you're comparing two trees,
think of traversing both trees simultaneously.
At every step, compare:
• Structure
• Node values
-------------------------------------------------------
*/