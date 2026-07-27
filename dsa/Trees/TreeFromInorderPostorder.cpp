#include <bits/stdc++.h>
using namespace std;

/*
==========================================================
Problem:
Construct a Binary Tree from its
Inorder and Postorder Traversals.

Approach:

1. The LAST element in postorder is always the root.
2. Find that root in the inorder traversal.
3. Everything to the left belongs to the left subtree.
4. Everything to the right belongs to the right subtree.
5. Since postorder follows Left -> Right -> Root,
   while traversing backwards it becomes:
   Root -> Right -> Left.
6. Therefore, recursively build the RIGHT subtree
   before the LEFT subtree.

Why it works:

- Postorder tells us which node to create.
- Inorder tells us how to split the tree.
- Recursively solving smaller inorder ranges
  reconstructs the original tree.

Time Complexity:
O(N log N) using map
(O(N) if unordered_map is used)

Space Complexity:
O(N)
(HashMap + recursion stack)
==========================================================
*/

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

void createMapping(int in[],
                   map<int,int> &nodeToIndex,
                   int n){

    for(int i=0;i<n;i++){
        nodeToIndex[in[i]]=i;
    }
}

Node* solve(int in[],
            int post[],
            int &postOrderIndex,
            int inorderStart,
            int inorderEnd,
            int n,
            map<int,int> &nodeToIndex){

    if(postOrderIndex<0 || inorderStart>inorderEnd)
        return NULL;

    int element=post[postOrderIndex--];

    Node* root=new Node(element);

    int position=nodeToIndex[element];

    // Build Right first
    root->right=solve(in,post,postOrderIndex,
                      position+1,inorderEnd,
                      n,nodeToIndex);

    root->left=solve(in,post,postOrderIndex,
                     inorderStart,position-1,
                     n,nodeToIndex);

    return root;
}

Node* buildTree(int in[],
                int post[],
                int n){

    int postOrderIndex=n-1;

    map<int,int> nodeToIndex;

    createMapping(in,nodeToIndex,n);

    return solve(in,post,postOrderIndex,
                 0,n-1,n,nodeToIndex);
}

void levelOrder(Node* root){

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        int size=q.size();

        while(size--){

            Node* temp=q.front();
            q.pop();

            cout<<temp->data<<" ";

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }

        cout<<endl;
    }
}

int main(){

    int inorder[]={4,8,2,5,1,6,3,7};
    int postorder[]={8,4,5,2,6,7,3,1};

    int n=8;

    Node* root=buildTree(inorder,postorder,n);

    cout<<"Level Order Traversal:\n";
    levelOrder(root);

    return 0;
}

/*
==========================================================
Mistakes to Avoid:

1. Don't forget that postorder starts from the END.

2. Always decrement postOrderIndex immediately
   after taking the current root.

3. Build RIGHT subtree before LEFT subtree.
   This is the most common interview mistake.

4. Pass postOrderIndex by reference.

5. Build the mapping only once before recursion.

⭐ GOLDEN Interview Tip ⭐

Remember these two formulas:

Preorder:
Root -> Left -> Right
=> Build Left first

Postorder:
Left -> Right -> Root

Traversing backwards:
Root -> Right -> Left
=> Build Right first

This single observation solves almost every
tree construction problem.

Pattern:
Inorder + Postorder → Build Tree
==========================================================
*/