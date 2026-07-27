#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: Burning Tree

Approach:
1. Perform BFS to create a mapping from every node to its parent.
2. Simultaneously locate the target node.
3. Start another BFS from the target node.
4. At every second, fire spreads to:
      • Left child
      • Right child
      • Parent
5. Every BFS level represents one unit of time.
6. Continue until all reachable nodes are burned.

Time Complexity:
O(N)

Space Complexity:
O(N)
(parent map + visited map + queue)
-------------------------------------------------------
*/

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

//------------------------------------------------------------
// Create Parent Mapping + Find Target Node
//------------------------------------------------------------
Node* createParentMapping(Node* root, int target,
                          map<Node*, Node*>& nodeToParent) {

    Node* result = NULL;

    queue<Node*> q;
    q.push(root);

    nodeToParent[root] = NULL;

    while (!q.empty()) {

        Node* front = q.front();
        q.pop();

        if (front->data == target)
            result = front;

        if (front->left) {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }

        if (front->right) {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }

    return result;
}

//------------------------------------------------------------
// Burn Tree using BFS
//------------------------------------------------------------
int burnTree(Node* root,
             map<Node*, Node*>& nodeToParent) {

    map<Node*, bool> visited;
    queue<Node*> q;

    q.push(root);
    visited[root] = true;

    int ans = 0;

    while (!q.empty()) {

        int size = q.size();
        bool flag = false;

        for (int i = 0; i < size; i++) {

            Node* front = q.front();
            q.pop();

            // Left
            if (front->left && !visited[front->left]) {
                flag = true;
                visited[front->left] = true;
                q.push(front->left);
            }

            // Right
            if (front->right && !visited[front->right]) {
                flag = true;
                visited[front->right] = true;
                q.push(front->right);
            }

            // Parent
            if (nodeToParent[front] &&
                !visited[nodeToParent[front]]) {

                flag = true;
                visited[nodeToParent[front]] = true;
                q.push(nodeToParent[front]);
            }
        }

        if (flag)
            ans++;
    }

    return ans;
}

//------------------------------------------------------------
// Main Function
//------------------------------------------------------------
int minTime(Node* root, int target) {

    map<Node*, Node*> nodeToParent;

    Node* targetNode =
        createParentMapping(root, target, nodeToParent);

    return burnTree(targetNode, nodeToParent);
}

//------------------------------------------------------------
// Main
//------------------------------------------------------------
int main() {

    /*
            1
          /   \
         2     3
        / \   / \
       4  5  6   7

       Target = 5
       Answer = 4
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int target = 5;

    cout << "Minimum Time = "
         << minTime(root, target);

    return 0;
}

/*
-------------------------------------------------------
Mistakes to Avoid

1. Forgetting parent mapping.
2. Using visited[node] instead of !visited[node].
3. Not marking visited before pushing into queue.
4. Variable name conflict with target.
5. Returning target value instead of target node.
6. Counting an extra second after the last level.

Interview Tip ⭐

Whenever movement is allowed:
    Left
    Right
    Parent

think of the tree as an Undirected Graph.

The standard pattern is:

Tree
   ↓
Parent Mapping
   ↓
Graph Traversal (BFS)

This pattern appears frequently in tree interview questions.
-------------------------------------------------------
*/