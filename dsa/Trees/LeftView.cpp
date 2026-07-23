#include <bits/stdc++.h>
using namespace std;

/*
------------------------------- PROBLEM -------------------------------

Return the Left View of a Binary Tree.

The Left View consists of the first node visible from the
left side at every level of the tree.

------------------------------- APPROACH ------------------------------

1. Perform a Level Order Traversal (BFS).

2. Process one complete level at a time.

3. For every level, the first node processed
   (i == 0) is the leftmost node.

4. Store this node in the answer.

5. Continue until all levels are processed.

----------------------------- WHY BFS? -------------------------------

BFS naturally processes nodes level by level.

Since the left child is pushed before the right child,
the first node visited at each level is always the
leftmost visible node.

Time Complexity  : O(N)
Space Complexity : O(N)

*/

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

/*
RECURISVE APPROACH: 
void solve(Node* root, vector<int>&ans, int level){
    if(root == NULL)
        return;
    
    if(level == ans.size())
        ans.push_back(root->data);

    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}
*/

vector<int> leftView(Node* root) {

    vector<int> ans;

    if(root == NULL) {
        return ans;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {

        int size = q.size();

        for(int i = 0; i < size; i++) {

            Node* frontNode = q.front();
            q.pop();

            // First node of every level
            if(i == 0) {
                ans.push_back(frontNode->data);
            }

            if(frontNode->left) {
                q.push(frontNode->left);
            }

            if(frontNode->right) {
                q.push(frontNode->right);
            }
        }
    }

    return ans;

    /*
    RECURSIVE APPROACH:
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
    */
}

int main() {

    /*
                1
              /   \
             2     3
            / \     \
           4   5     6
              /
             7

        Left View = 1 2 4 7
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(6);

    root->left->right->left = new Node(7);

    vector<int> ans = leftView(root);

    cout << "Left View: ";

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}

/*
------------------------- COMMON MISTAKES -------------------------

1. Writing

       if(i = 0)

   instead of

       if(i == 0)

2. Using push_back() on a queue.

3. Enqueuing the right child before the left child.

   Wrong:
       Right
       Left

   Correct:
       Left
       Right

4. Forgetting to process level by level.

------------------------- INTERVIEW TIP ---------------------------

The Left View is simply:

"The FIRST node encountered at every level."

Similarly,

Left View  -> First node of each level
Right View -> Last node of each level

Pattern:

Tree
→ Level Order Traversal (BFS)
→ Level-wise Processing

*/