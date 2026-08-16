#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data){
    //base case
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        //right subtree
        root->right = insertIntoBST(root->right, data);
    }else{
        //left subtree
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void inorder(Node* root){
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout<<root->left<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void takeInput(Node* root){
    int data;
    cin>>data;
    while(data != -1){
        insertIntoBST(root, data);
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main(){
    Node* root = NULL;
    cout<<"Enter data to create BST: "<<endl;
    takeInput(root);

    cout<<"Printting the BST"<<endl;
    levelOrderTraversal(root);

    cout<<"\nPrinting Inorder: "<<endl;
    inorder(root);

    cout<<"\nPrinting preorder: "<<endl;
    preorder(root);

    cout<<"\nPrinting postorder: "<<endl;
    postorder(root);
}