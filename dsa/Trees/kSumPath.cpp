#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
Problem: Count K Sum Paths in a Binary Tree
-------------------------------------------------------
Approach:
1. Perform a DFS traversal while maintaining the current
   root-to-node path.
2. Add the current node to the path.
3. Recursively explore both subtrees.
4. After visiting children, traverse the current path
   backwards and calculate suffix sums.
5. If any suffix sum equals K, increment the count.
6. Backtrack by removing the current node before returning.

Time Complexity : O(N²) Worst Case
                 O(N log N) Average (balanced tree)

Space Complexity: O(H)
where H is the height of the tree.
-------------------------------------------------------
*/

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void solve(Node* root, int k, int &count, vector<int> path){

    if(root == NULL)
        return;

    path.push_back(root->data);

    solve(root->left, k, count, path);
    solve(root->right, k, count, path);

    int sum = 0;

    for(int i = path.size()-1; i >= 0; i--){
        sum += path[i];

        if(sum == k)
            count++;
    }

    path.pop_back();
}

int sumK(Node* root, int k){

    vector<int> path;
    int count = 0;

    solve(root, k, count, path);

    return count;
}

int main(){

    /*
                1
              /   \
             3    -1
            / \   / \
           2   1 4   5
              /  / \
             1  1   2

    K = 5

    Paths:
    3 -> 2
    3 -> 1 -> 1
    1 -> 3 -> 1
    4 -> 1

    Answer = 4
    */

    Node* root = new Node(1);

    root->left = new Node(3);
    root->right = new Node(-1);

    root->left->left = new Node(2);
    root->left->right = new Node(1);

    root->left->right->left = new Node(1);

    root->right->left = new Node(4);
    root->right->right = new Node(5);

    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);

    cout << "Number of paths = "
         << sumK(root,5);

    return 0;
}

/*
-------------------------------------------------------
Mistakes to Avoid
-------------------------------------------------------
1. Forgetting to initialize sum = 0 before checking suffix sums.
2. Traversing the path from front instead of back.
3. Not adding the current node before recursive calls.
4. Forgetting to backtrack after processing the node.
5. Passing count by value instead of reference.

⭐ Interview Tip:
The backward traversal checks every path ending at the
current node. This is a common tree backtracking pattern.
For an optimized O(N) solution, use Prefix Sum + HashMap.
-------------------------------------------------------
*/