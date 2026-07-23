#include <bits/stdc++.h>
using namespace std;

/*
------------------------------- PROBLEM -------------------------------

Return the Diagonal Traversal of a Binary Tree.

Nodes lying on the same diagonal are printed together.

Rule:

Right Child -> Same Diagonal
Left Child  -> Next Diagonal

------------------------------- APPROACH ------------------------------

1. Push the root into a queue.

2. Pop one node.

3. Traverse along its right chain.

4. While moving right:
      - Store every node.
      - Push every left child into the queue.

5. Once the right chain ends,
   process the next node from the queue.

6. Continue until the queue becomes empty.

----------------------------- WHY IT WORKS ----------------------------

Moving right keeps us on the same diagonal.

Every left child starts a new diagonal, so we save it
for later using the queue.

Time Complexity  : O(N)
Space Complexity : O(N)

*/

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

vector<int> diagonal(Node* root){

    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        while(temp){

            ans.push_back(temp->data);

            if(temp->left){
                q.push(temp->left);
            }

            temp = temp->right;
        }
    }

    return ans;
}

int main(){

    /*
                8
              /   \
             3     10
            / \      \
           1   6      14
              / \     /
             4   7   13

    Diagonal Traversal:
    8 10 14 3 6 7 13 1 4
    */

    Node* root = new Node(8);

    root->left = new Node(3);
    root->right = new Node(10);

    root->left->left = new Node(1);
    root->left->right = new Node(6);

    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    vector<int> ans = diagonal(root);

    cout << "Diagonal Traversal: ";

    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}

/*
-------------------------- COMMON MISTAKES --------------------------

1. Traversing left immediately.

   Wrong:
      temp = temp->left;

   Right child always belongs to the same diagonal.

2. Forgetting to push the left child into the queue.

3. Forgetting the inner while(temp) loop.

4. Confusing Diagonal Traversal with Vertical Traversal.

   Vertical:
       Uses HD (Horizontal Distance)

   Diagonal:
       No HD required.

-------------------------- INTERVIEW TIP ----------------------------

Think of every diagonal as one continuous
RIGHT chain.

Whenever you see a LEFT child,

don't visit it immediately—

store it in the queue because it starts
the next diagonal.

Pattern:

Tree
→ Queue
→ Keep Moving Right
→ Save Left Children

*/