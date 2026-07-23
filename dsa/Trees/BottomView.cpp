#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------- PROBLEM --------------------------------

Return the Bottom View of a Binary Tree.

The Bottom View consists of the last node visible at every
Horizontal Distance (HD) when looking at the tree from below.

Left Child  -> HD - 1
Right Child -> HD + 1

------------------------------- APPROACH -------------------------------

1. Perform a Level Order Traversal (BFS).

2. Assign every node a Horizontal Distance (HD).

3. Maintain:

       map<HD, NodeValue>

4. Unlike Top View, always overwrite the value stored for
   each HD because deeper (or later visited) nodes should
   appear in the Bottom View.

5. Traverse the map from leftmost HD to rightmost HD to
   construct the answer.

---------------------------- WHY BFS? ----------------------------------

BFS processes nodes level by level.

Since lower-level nodes are visited after higher-level nodes,
overwriting ensures the last visible node for each HD is stored.

Time Complexity  : O(N log N)
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

vector<int> BottomView(Node* root) {

    vector<int> ans;

    if(root == NULL) {
        return ans;
    }

    map<int,int> bottomNode;
    queue<pair<Node*,int>> q;

    q.push(make_pair(root,0));

    while(!q.empty()) {

        pair<Node*,int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // Always overwrite for Bottom View
        bottomNode[hd] = frontNode->data;

        if(frontNode->left) {
            q.push(make_pair(frontNode->left,hd-1));
        }

        if(frontNode->right) {
            q.push(make_pair(frontNode->right,hd+1));
        }
    }

    for(auto i : bottomNode) {
        ans.push_back(i.second);
    }

    return ans;
}

int main() {

    /*
                1
              /   \
             2     3
              \   / \
               4 5   6
                  \
                   7

        Bottom View = 2 5 7 6
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(4);

    root->right->left = new Node(5);
    root->right->right = new Node(6);

    root->right->left->right = new Node(7);

    vector<int> ans = BottomView(root);

    cout << "Bottom View: ";

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}

/*
-------------------------- COMMON MISTAKES --------------------------

1. Using the Top View condition:

       if(map.find(hd) == map.end())

   This is WRONG for Bottom View.

2. Forgetting q.pop().

3. Using q.first instead of q.front().

4. Mixing Horizontal Distance updates.

   Left  -> hd - 1
   Right -> hd + 1

5. Using DFS without tracking levels.
   BFS naturally processes nodes from top to bottom,
   making overwriting straightforward.

-------------------------- INTERVIEW TIP ----------------------------

Top View and Bottom View differ by just one line.

Top View:
    Store only the FIRST node for every HD.

Bottom View:
    ALWAYS overwrite the node for every HD.

Pattern:

Tree
→ BFS
→ Horizontal Distance
→ Ordered Map

Remember:

Top View    = First node at each HD
Bottom View = Last node at each HD

*/