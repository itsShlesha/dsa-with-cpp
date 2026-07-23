#include <bits/stdc++.h>
using namespace std;

/*
------------------------------- PROBLEM -------------------------------

Return the Right View of a Binary Tree.

The Right View consists of the last node visible from the
right side at every level of the tree.

------------------------------- APPROACH ------------------------------

1. Perform a Level Order Traversal (BFS).

2. Process one complete level at a time.

3. For every level, the last node processed
   (i == size - 1) is the rightmost node.

4. Store this node in the answer.

5. Continue until all levels are processed.

----------------------------- WHY BFS? -------------------------------

BFS naturally processes nodes level by level.

Since nodes are processed level-wise, the last node
encountered at every level is always the rightmost
visible node.

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

    solve(root->right, ans, level+1);
    solve(root->left, ans, level+1);
}
*/

vector<int> rightView(Node* root) {

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

            // Last node of every level
            if(i == size - 1) {
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

        Right View = 1 3 6 7
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(6);

    root->left->right->left = new Node(7);

    vector<int> ans = rightView(root);

    cout << "Right View: ";

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}

/*
------------------------- COMMON MISTAKES -------------------------

1. Writing

       if(i == 0)

   instead of

       if(i == size - 1)

2. Forgetting to process nodes level by level.

3. Using DFS without tracking levels correctly.

4. Confusing Left View and Right View.

------------------------- INTERVIEW TIP ---------------------------

The Left View and Right View are mirror problems.

Left View  -> First node of every level.
Right View -> Last node of every level.

Both are solved using:

✔ Level Order Traversal (BFS)
✔ Level-wise Processing

Pattern:

Tree
→ BFS
→ Level Traversal

*/