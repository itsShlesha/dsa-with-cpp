#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
            this->prev = NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};

int getLength(Node* &head){
    int length = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        length++;
    }
    return length;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }else{
        Node* temp = new Node(data);
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node* head, Node* &tail, int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }else{
        Node* temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int pos, int data){
    int length = getLength(head);
    if(pos == 1){
        insertAtHead(head, tail, data);
        return;
    }
    else if(pos == length){
        insertAtTail(head, tail, data);
    }
    else{
        Node* temp = head;
        int count = 1;
        while(count <= (pos-1)){
            temp = temp->next;
            count++;
        }
        Node* nodeToInsert = new Node(data);
        temp->next->prev = nodeToInsert;
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
        nodeToInsert->prev = temp;
    }
}

void deleteNode(Node* &head, Node* &tail, int pos){
    if(pos == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int count = 1; 
        while(count < pos){
            prev = curr;
            curr = curr->next;
            if(curr->next == NULL){
                tail = prev;
            }
            count++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node* &head){
    Node* temp = head;
    cout<<"NULL <-> ";
    while(temp != NULL){
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, tail, 11);
    insertAtTail(head, tail, 12);
    insertAtPosition(head, tail, 3, 23);
    print(head);
    cout<<getLength(head)<<endl;
    deleteNode(head, tail, 4);
    print(head);
    cout<<getLength(head)<<endl;
    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl; 
}