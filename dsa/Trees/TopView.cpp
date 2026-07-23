#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------- PROBLEM --------------------------------

Return the Top View of a Binary Tree.

The Top View consists of the first node visible at every
Horizontal Distance (HD) when looking at the tree from above.

Left Child  -> HD - 1
Right Child -> HD + 1

------------------------------- APPROACH -------------------------------

1. Perform a Level Order Traversal (BFS).

2. Assign every node a Horizontal Distance (HD).

3. Maintain:

       map<HD, NodeValue>

4. Since BFS visits nodes level by level, the first node
   encountered at each HD is the topmost node.

5. Ignore all future nodes having the same HD.

6. Finally traverse the map from leftmost HD to rightmost HD
   to obtain the Top View.

---------------------------- WHY BFS? ----------------------------------

BFS guarantees that higher-level nodes are processed before
lower-level nodes.

Therefore, the first node seen for any HD is always the
correct node for the Top View.

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

vector<int> topView(Node* root) {

    vector<int> ans;

    if(root == NULL) {
        return ans;
    }

    map<int,int> topNode;
    queue<pair<Node*,int>> q;

    q.push(make_pair(root,0));

    while(!q.empty()) {

        pair<Node*,int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // Store only the first node seen at each HD
        if(topNode.find(hd) == topNode.end()) {
            topNode[hd] = frontNode->data;
        }

        if(frontNode->left) {
            q.push(make_pair(frontNode->left,hd-1));
        }

        if(frontNode->right) {
            q.push(make_pair(frontNode->right,hd+1));
        }
    }

    for(auto i : topNode) {
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

        Top View = 2 1 3 6
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(4);

    root->right->left = new Node(5);
    root->right->right = new Node(6);

    root->right->left->right = new Node(7);

    vector<int> ans = topView(root);

    cout << "Top View: ";

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}

/*
-------------------------- COMMON MISTAKES --------------------------

1. Forgetting q.pop() after processing a node.

2. Overwriting an already stored HD.

   Wrong:
       topNode[hd] = node->data;

   Correct:
       if(topNode.find(hd) == topNode.end())
           topNode[hd] = node->data;

3. Mixing HD updates.

   Left  -> hd - 1
   Right -> hd + 1

4. Using DFS.

   DFS may visit deeper nodes before shallower ones,
   producing an incorrect Top View.

-------------------------- INTERVIEW TIP ----------------------------

Think of Top View as:

"For every Vertical Line, keep the FIRST node."

Pattern:

Tree
→ BFS
→ Horizontal Distance
→ Ordered Map

A quick memory trick:

Top View    → First node at every HD
Bottom View → Last node at every HD

*/