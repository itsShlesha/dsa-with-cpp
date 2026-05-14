#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};

void insertNode(Node* &tail, int element, int data){
    if(tail == NULL){
        Node* newnode = new Node(data);
        tail = newnode;
        newnode->next = tail;
    }
    else{
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }

        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail, int value){
    if(tail == NULL) cout<<"List is empty";
    else if(tail->next == tail && tail->data == value){
            delete tail;
            tail = NULL;
        }
    else{
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        if(tail == curr) tail = prev;
        curr->next = NULL;

        delete curr;
    }
}

void print(Node* tail){
    Node* temp = tail;
    do{
        cout<<tail->data<<" -> ";
        tail = tail->next;
    }while(tail != temp);
    cout<<endl;
}

int main(){
    Node* tail = NULL;

    insertNode(tail, 5, 3);

    print(tail);

    deleteNode(tail, 3);
    print(tail);
}