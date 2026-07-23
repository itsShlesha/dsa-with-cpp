#include <bits/stdc++.h>
using namespace std;

/*
Approach:
1. Perform a normal Level Order Traversal using a Queue.
2. For every level, create a temporary vector of size = current level size.
3. If traversing Left → Right, place elements normally.
4. If traversing Right → Left, place elements at reversed indices.
5. Toggle the traversal direction after every level.
6. Append the current level into the final answer.

Time Complexity: O(N)
Space Complexity: O(N)

Reason:
- Every node is visited exactly once.
- Queue and temporary vector together take O(N) space.
*/

// Definition of a Binary Tree Node
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

// Function to perform Zig-Zag (Spiral) Level Order Traversal
vector<int> zigZagTraversal(Node* root){

    // Stores the final traversal
    vector<int> result;

    // Base case
    if(root == NULL){
        return result;
    }

    queue<Node*> q;
    q.push(root);

    // Direction flag
    bool leftToRight = true;

    while(!q.empty()){

        int size = q.size();

        // Stores current level in desired order
        vector<int> ans(size);

        for(int i = 0; i < size; i++){

            Node* frontNode = q.front();
            q.pop();

            // Decide index based on traversal direction
            int index = leftToRight ? i : size - i - 1;

            ans[index] = frontNode->data;

            if(frontNode->left)
                q.push(frontNode->left);

            if(frontNode->right)
                q.push(frontNode->right);
        }

        // Change direction for next level
        leftToRight = !leftToRight;

        // Add current level into final answer
        for(auto i : ans){
            result.push_back(i);
        }
    }

    return result;
}

int main(){

    /*
            1
          /   \
         2     3
        / \   / \
       4  5  6   7
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = zigZagTraversal(root);

    cout << "Zig-Zag Traversal : ";

    for(int x : ans){
        cout << x << " ";
    }

    cout << endl;

    return 0;
}

/*
Mistakes to Avoid:
1. Initialize the level vector with size:
   vector<int> ans(size);
   Otherwise ans[index] causes out-of-bounds access.

2. Return 'result', not 'ans' when root == NULL.

3. While appending into result:
   result.push_back(i);
   NOT result.push_back(ans);

4. Reverse the index, not the queue.
   Queue should always process nodes in normal level-order.

5. Toggle direction only after completing an entire level.

⭐ Interview Tip:
Most interviewers expect the Queue + Index Mapping approach instead of physically reversing each level because it avoids an extra O(Level Size) reverse operation.
*/