#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
BUILD BINARY TREE USING LEVEL ORDER TRAVERSAL (BFS)
-------------------------------------------------------

Approach:
1. Create the root node.
2. Push the root into a queue.
3. While the queue is not empty:
   - Pop the front node.
   - Ask for its left child.
       -> If value != -1, create the node and push it into the queue.
   - Ask for its right child.
       -> If value != -1, create the node and push it into the queue.
4. Continue until every node has been processed.

Why Queue?
- Queue follows FIFO order.
- It processes nodes level by level, making it ideal for Level Order Traversal.

Time Complexity : O(n)
Space Complexity: O(n)
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

void buildFromLevelOrder(node* &root){

    cout << "Enter data for root: ";
    int data;
    cin >> data;

    if(data == -1)
        return;

    root = new node(data);

    queue<node*> q;
    q.push(root);

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        cout << "Enter left node of " << temp->data << ": ";
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node of " << temp->data << ": ";
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main(){

    node* root = NULL;

    buildFromLevelOrder(root);

    return 0;
}

/*
-------------------------------------------------------
IMPORTANT NOTES / COMMON MISTAKES
-------------------------------------------------------

1. Always use 'temp->data' while processing the current node.
   Using 'root->data' will always print the root value.

2. '-1' is used as a NULL marker.
   If the input is -1, no child node is created.

3. Every newly created child must be pushed into the queue.
   Otherwise, its children will never be processed.

4. Queue stores node pointers, not node values.

5. If the root itself is -1, return immediately to create an empty tree.

GOLDEN INTERVIEW TIP:
Whenever you're asked to construct a tree level-wise,
think of Queue + BFS.
The queue always contains the nodes whose children
are yet to be inserted.
-------------------------------------------------------
*/