#include <iostream>
using namespace std;

/*
Problem Statement:
Reverse a doubly linked list
and return the new head.

Example:
Input:
NULL <-> 10 <-> 11 <-> 12 <-> NULL

Output:
NULL <-> 12 <-> 11 <-> 10 <-> NULL


Approach:
For every node:
- swap next and prev pointers
- move ahead in reversed direction

Steps:
1. Store previous pointer temporarily
2. Swap prev and next
3. Move curr forward
4. Update head at the end


Why This Approach?
In a doubly linked list,
every node has:
- next pointer
- prev pointer

To reverse the list,
both directions must be reversed.

So for every node:
next becomes prev
prev becomes next

This reverses traversal direction completely.


Time Complexity:
O(n)

Each node is visited once.


Space Complexity:
O(1)

Only pointers are used.
*/

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

Node* reverse(Node* &head){
    if(head == NULL || head->next == NULL) return head;

    Node* curr = head; Node* temp = NULL;

    while(curr != NULL){

        //swap prev and next
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        //move to next node
        curr = curr->prev;
    }

    //temp ends one step behind
    if(temp != NULL) head = temp->prev;

    return head;
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

    insertAtTail(head, tail, 11);
    insertAtTail(head, tail, 12);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 20);
    print(head);

    head = reverse(head);
    print(head);
}

/*
Mistakes I Made To Avoid:

1. Incorrect swapping logic
Wrong:
curr->prev = curr->next;
curr->next = temp;

Reason:
Both pointers can become same.

Correct:
store old prev first,
then swap properly.


2. Forgetting DLL reversal concept
In singly LL:
only next changes.

In doubly LL:
BOTH next and prev must swap.


3. Moving pointer incorrectly
After swapping:
curr = curr->prev

Reason:
direction becomes reversed after swap.


4. Forgetting head update
After reversal:
old tail becomes new head.


5. Confusing temp usage
temp stores old prev pointer,
not next pointer.


6. Forgetting edge cases
Handle:
- empty list
- single node list


7. Thinking traversal direction remains same
After swapping links,
forward movement changes direction.



GOLDEN Interview Tips:

1. DLL reversal is simpler conceptually
than singly linked list reversal.


2. Core interview line:
“Swap next and prev for every node.”


3. Always explain why:
curr = curr->prev

works after swapping.


4. Draw one node separately first:
prev <- curr -> next

After swap:
next <- curr -> prev


5. Mention:
“No extra memory required.”

Important optimization point.


6. Pointer problems become easier
when solved visually.


7. Most DLL problems are about:
- correct swapping
- correct traversal direction
- proper head/tail updates
*/