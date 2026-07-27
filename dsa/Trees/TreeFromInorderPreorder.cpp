#include <bits/stdc++.h>
using namespace std;

/*
=========================================
Problem:
Construct a Binary Tree using its
Inorder and Preorder Traversals.

Approach:
1. The first element in preorder is always
   the root.
2. Find that root in inorder.
3. Everything left of it belongs to the left subtree.
4. Everything right belongs to the right subtree.
5. Recursively repeat the process.

Why it works:
Preorder tells us the root order.
Inorder tells us how to split the tree.

Time Complexity:
O(N²)
(findPos() takes O(N) for every node)

Space Complexity:
O(H)
Recursive stack
(H = tree height)
=========================================
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

int findPos(int in[], int element, int n){
    for(int i=0;i<n;i++){
        if(in[i]==element)
            return i;
    }
    return -1;
}

Node* solve(int in[], int pre[], int &index,
            int inOrderStart, int inOrderEnd, int n){

    if(index>=n || inOrderStart>inOrderEnd)
        return NULL;

    int element = pre[index++];
    Node* root = new Node(element);

    int position = findPos(in, element, n);

    root->left = solve(in, pre, index,
                       inOrderStart, position-1, n);

    root->right = solve(in, pre, index,
                        position+1, inOrderEnd, n);

    return root;
}

Node* buildTree(int in[], int pre[], int n){

    int preOrderIndex = 0;

    return solve(in, pre, preOrderIndex, 0, n-1, n);
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

    int inorder[]  = {3,1,4,0,5,2};
    int preorder[] = {0,1,3,4,2,5};

    int n = 6;

    Node* root = buildTree(inorder, preorder, n);

    cout<<"Level Order Traversal:\n";
    levelOrder(root);

    return 0;
}

/*
=========================================
Mistakes to Avoid:

1. Pass preorder index by reference.
   Passing by value breaks recursion.

2. Base condition:
   inStart > inEnd

3. Increment preorder index immediately
   after creating the root.

4. Build LEFT subtree before RIGHT subtree.
   That's how preorder works.

5. Don't forget to pass 'n' into recursive calls.

⭐ GOLDEN Interview Tip ⭐

This O(N²) solution is acceptable for small inputs,
but interviewers usually expect O(N).

Optimize by storing:
unordered_map<int,int> inorderIndex;

This makes searching the root position O(1),
reducing overall complexity to O(N).

Pattern:
Preorder + Inorder → Build Tree
=========================================
*/