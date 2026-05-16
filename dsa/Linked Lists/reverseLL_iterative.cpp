#include <iostream>
using namespace std;

/*
Problem Statement:
Reverse a singly linked list iteratively and return the new head.

Example:
Input:
10 -> 11 -> 12 -> 13 -> NULL

Output:
13 -> 12 -> 11 -> 10 -> NULL


Approach:
Use 3 pointers:
1. prev   -> stores previous node
2. curr   -> current node
3. forward -> stores next node temporarily

For every node:
- save next node
- reverse current link
- move prev forward
- move curr forward

Finally, prev becomes the new head.


Why This Approach?
While reversing links, we can lose access to the remaining list.
So we store the next node beforehand using 'forward'.

This method reverses the list in-place:
- no extra array
- no recursion stack
- optimal approach for interviews


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

Node* reverse(Node* head){
    if (head == NULL || head->next == NULL) return head;

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
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

    head = reverse(head);
    cout<<"New Head at: "<<head->data<<endl;

    print(head);

}

/*
Mistakes I Made To Avoid:

1. Forgot to update head
Wrong:
reverse(head);

Correct:
head = reverse(head);

Reason:
reverse() returns the NEW head.


2. Printed the returned pointer directly
Wrong:
cout << reverse(head);

This prints memory address.

Correct:
head = reverse(head);
cout << head->data;


3. Printed old head after reversal
After reversing:
old head becomes tail.

If head is not updated,
printing starts from wrong node.


4. Losing links accidentally
If forward is not stored before:
curr->next = prev;

remaining list gets lost.


5. Incorrect loop order
Correct order:
- store next
- reverse link
- move prev
- move curr

Changing order can break the list.



GOLDEN Interview Tips:

1. Dry run pointer problems on paper
Linked list bugs are mostly pointer movement mistakes.


2. Always draw before coding
Visualizing:
prev <- curr -> forward
makes debugging much easier.


3. Mention edge cases before interviewer asks
Handle:
- empty list
- single node list


4. Explain WHY forward pointer is needed
Interviewers care more about reasoning than syntax.


5. Say “in-place reversal”
This is an important optimization keyword.


6. Never lose the original list accidentally
If you change links before saving next node,
the remaining nodes become unreachable.


7. Return prev, not curr
At loop end:
curr becomes NULL
prev points to new head.
*/