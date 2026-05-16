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
Use recursion to reverse the remaining list first.

Steps:
1. Recursively reverse nodes after current node
2. Reverse current connection
3. Break old forward link
4. Return new head

Core Idea:
Suppose:
10 -> 11 -> 12 -> 13

Recursive call first reverses:
11 -> 12 -> 13

which becomes:
13 -> 12 -> 11

Then:
11 points back to 10.


Why This Approach?
Recursion naturally reaches the last node first.

While returning from recursive calls,
we reverse links one by one.

This creates an elegant reverse traversal
without explicit loops.


Time Complexity:
O(n)

Each node is visited once.


Space Complexity:
O(n)

Recursive call stack stores n function calls.
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
    //base case
    if (head == NULL || head->next == NULL) return head;

    Node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;  

    return newHead;
}

Node* reverseLinkedList(Node* head){

    return reverse(head);
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

1. Forgetting to break old links
Wrong:
head->next->next = head;

without:
head->next = NULL;

Reason:
Creates cycle in linked list.


2. Returning wrong node
Wrong:
return head;

Correct:
return newHead;

Reason:
Original head becomes tail after reversal.


3. Confusing recursion flow
Recursive calls go FORWARD first,
reversal happens while BACKTRACKING.


4. Missing base case
Without:
if(head == NULL || head->next == NULL)

recursion never stops.


5. Thinking pass-by-reference is required
Not needed here because:
new head is returned explicitly.


6. Forgetting recursive space complexity
Even without loops,
recursive stack still uses O(n) space.


7. Losing track of current structure
After:
head->next->next = head

current node becomes previous node.



GOLDEN Interview Tips:

1. Explain recursion in two phases:
- descending phase
- backtracking phase

Interviewers love this clarity.


2. Clearly state:
“Last node becomes new head.”

This is the core recursive insight.


3. Mention why:
head->next = NULL

is necessary.

Otherwise cyclic linked list forms.


4. Draw recursive stack for understanding
Linked list recursion becomes much easier visually.


5. Recursive solution is elegant,
iterative solution is more space optimized.

Mention both in interviews.


6. Base case should return the node
that becomes final answer.

Here:
last node becomes new head.


7. This pattern is common in:
- linked list reversal
- tree recursion
- backtracking problems

Understanding flow deeply helps everywhere.
*/