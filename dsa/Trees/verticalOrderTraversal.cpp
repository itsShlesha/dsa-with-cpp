#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------- PROBLEM ----------------------------------

Print the Vertical Order Traversal of a Binary Tree.

Nodes are grouped according to their Horizontal Distance (HD):
- Left child  -> HD - 1
- Right child -> HD + 1

If multiple nodes share the same HD, they are ordered from
top to bottom (level order).

---------------------------------- APPROACH ---------------------------------

1. Perform a Level Order Traversal (BFS).
2. Store every node using:
      map<HD, map<Level, vector<Node>>>

   HD    -> keeps vertical lines sorted.
   Level -> keeps nodes top to bottom.
   Vector-> stores multiple nodes occurring at same position.

3. Finally traverse the map from leftmost HD to rightmost HD
   and collect every node.

-------------------------------- WHY BFS? -----------------------------------

BFS naturally visits nodes level by level.

When multiple nodes lie on the same Vertical Line and Level,
their left-to-right order is automatically preserved because
BFS processes parents before children.

Time Complexity  : O(N log N)
Space Complexity : O(N)

*/

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

vector<int> verticalOrder(Node* root) {
    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node*, pair<int,int>>> q;
    vector<int> ans;

    if(root == NULL) {
        return ans;
    }

    q.push(make_pair(root, make_pair(0,0)));

    while(!q.empty()) {

        pair<Node*, pair<int,int>> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left) {
            q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
        }

        if(frontNode->right) {
            q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
        }
    }

    for(auto i : nodes) {
        for(auto j : i.second) {
            for(auto k : j.second) {
                ans.push_back(k);
            }
        }
    }

    return ans;
}

int main() {

    /*
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = verticalOrder(root);

    cout << "Vertical Order Traversal: ";
    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}

/*
--------------------------- COMMON MISTAKES ---------------------------

1. Forgetting q.pop(), leading to an infinite loop.

2. Using insert() instead of push_back() for vectors.

3. Forgetting one '>' in:
      queue<pair<Node*, pair<int,int>>>

4. Using DFS instead of BFS.
   DFS cannot guarantee left-to-right ordering for nodes
   having the same Horizontal Distance and Level.

5. Mixing up Horizontal Distance:
      Left  -> hd - 1
      Right -> hd + 1

--------------------------- INTERVIEW TIP -----------------------------

This problem is mainly a combination of:

✔ Level Order Traversal (BFS)
✔ Coordinate Assignment (HD & Level)
✔ Ordered Maps

If asked "Why BFS instead of DFS?"

Answer:
Because BFS naturally preserves top-to-bottom and left-to-right
ordering for nodes sharing the same vertical line.

Pattern:
Tree + BFS + Coordinate Mapping + Ordered Map

*/