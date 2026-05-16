#include <iostream>
using namespace std;

/*
Problem Statement:
Reverse a singly linked list recursively
and return the new head.

Example:
Input:
10 -> 11 -> 12 -> 13 -> NULL

Output:
13 -> 12 -> 11 -> 10 -> NULL


Approach:
Use recursion with 3 pointers:
1. head  -> updated final head
2. curr  -> current node
3. prev  -> previous node

For every recursive call:
- store next node
- reverse current link
- move curr ahead
- move prev ahead

Base Case:
When curr becomes NULL,
prev points to the new head.


Why This Approach?
Recursion automatically handles traversal
through function call stack.

Each function call reverses one link.

This method:
- reverses list in-place
- avoids extra data structures
- is a classic recursive linked list pattern


Time Complexity:
O(n)

Space Complexity:
O(n)
Recursive call stack is used.
*/

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

void reverse(Node* &head, Node* curr, Node* prev){
    //base case
    if(curr == NULL){
        head = prev;
        return;
    }

    reverse(head, curr->next, curr);
    curr->next = prev;
}

Node* reverseLinkedList(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    reverse(head, curr, prev);
    return head;
}

void InsertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    InsertAtTail(tail,11);
    InsertAtTail(tail,12);
    InsertAtTail(tail,13);
    InsertAtTail(tail,14);
    InsertAtTail(tail,15);
    InsertAtTail(tail,16);

    cout<<"Current head at: "<<head->data<<endl;

    print(head);

    head = reverseLinkedList(head);
    cout<<"New Head at: "<<head->data<<endl;

    print(head);

}

/*
Mistakes I Made To Avoid:

1. Passed head by value
Wrong:
void reverse(Node* head, ...)

Correct:
void reverse(Node* &head, ...)

Reason:
Head must be updated globally.


2. Reversed links AFTER recursion
Wrong:
reverse(...)
curr->next = prev;

Correct:
curr->next = prev;
reverse(...)

Reason:
Links should reverse before moving ahead.


3. Forgot to store next node
Wrong:
curr = curr->next

after changing links.

Reason:
Remaining list gets lost.


4. Forgot recursive space complexity
Recursive solution is NOT O(1).

Call stack uses O(n) space.


5. Printing old head after reversal
Old head becomes tail after reversal.



GOLDEN Interview Tips:

1. Recursive linked list problems become easier
when visualized node by node.


2. Always explain:
“What does one recursive call do?”

Interviewers look for recursion understanding.


3. Mention stack space separately
Many candidates forget recursive space complexity.


4. Base case should clearly define
when recursion stops.


5. In linked lists,
save next node BEFORE changing links.


6. Use pass-by-reference carefully
when original head must change.


7. Recursive reversal is elegant,
but iterative reversal is more space optimized.
*/