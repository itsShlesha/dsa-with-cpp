#include <bits/stdc++.h>
using namespace std;

/*
-------------------------------------------------------
TREE TRAVERSALS (RECURSIVE & ITERATIVE)
-------------------------------------------------------

Recursive Traversals:

1. Inorder (LNR)
   Left -> Root -> Right

2. Preorder (NLR)
   Root -> Left -> Right

3. Postorder (LRN)
   Left -> Right -> Root


Iterative Traversals:

Inorder:
- Keep moving left while pushing nodes.
- Pop, visit node, then move to right subtree.

Preorder:
- Visit node first.
- Push right child before left child so that
  left subtree is processed first.

Postorder (Using Two Stacks):
- First stack processes nodes in Root-Right-Left order.
- Second stack reverses it to Left-Right-Root.

Time Complexity : O(n)
Space Complexity: O(h) Recursive
                  O(n) Iterative (Worst Case)
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

void inorder(node* root){
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node* root){
    if(root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inorderIterative(node* root){
    stack<node*> st;
    node* curr = root;

    while(curr != NULL || !st.empty()){

        while(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}

void preorderIterative(node* root){

    if(root == NULL)
        return;

    stack<node*> st;
    st.push(root);

    while(!st.empty()){

        node* temp = st.top();
        st.pop();

        cout << temp->data << " ";

        if(temp->right)
            st.push(temp->right);

        if(temp->left)
            st.push(temp->left);
    }
}

void postorderIterative(node* root){

    if(root == NULL)
        return;

    stack<node*> s1, s2;

    s1.push(root);

    while(!s1.empty()){

        node* temp = s1.top();
        s1.pop();

        s2.push(temp);

        if(temp->left)
            s1.push(temp->left);

        if(temp->right)
            s1.push(temp->right);
    }

    while(!s2.empty()){
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main(){

    /*
             1
           /   \
          2     3
         / \   / \
        4  5  6   7
    */

    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<"Recursive Inorder : ";
    inorder(root);

    cout<<"\nRecursive Preorder : ";
    preorder(root);

    cout<<"\nRecursive Postorder : ";
    postorder(root);

    cout<<"\n\nIterative Inorder : ";
    inorderIterative(root);

    cout<<"\nIterative Preorder : ";
    preorderIterative(root);

    cout<<"\nIterative Postorder : ";
    postorderIterative(root);

    return 0;
}

/*
-------------------------------------------------------
IMPORTANT NOTES / COMMON MISTAKES
-------------------------------------------------------

1. Inorder:
   Keep pushing LEFT nodes until NULL.

2. Preorder:
   Push RIGHT child first, then LEFT child.
   (Stack is LIFO.)

3. Postorder:
   One-stack solution is tricky.
   Two-stack solution is easier to understand
   and commonly asked in interviews.

4. Every node is visited exactly once.

5. Recursive traversal uses the function call stack,
   while iterative traversal uses an explicit stack.

Traversal Orders:

Inorder   : Left -> Root -> Right
Preorder  : Root -> Left -> Right
Postorder : Left -> Right -> Root

GOLDEN INTERVIEW TIP:
Remember the three patterns:

LNR → Inorder
NLR → Preorder
LRN → Postorder

For iterative traversals:
• Inorder = Stack + Left chain
• Preorder = Stack (Right then Left)
• Postorder = Two Stacks (or One Stack optimized)
-------------------------------------------------------
*/