#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
Reverse nodes of a linked list in groups of size k.

If remaining nodes are fewer than k,
leave them as it is.

Example:
Input:
1 -> 2 -> 3 -> 4 -> 5
k = 2

Output:
2 -> 1 -> 4 -> 3 -> 5


Approach:
1. Check whether k nodes exist
2. Reverse first k nodes iteratively
3. Recursively solve remaining list
4. Connect reversed group with recursive answer

Each recursive call handles one group.


Why This Approach?
Linked list reversal for one group is independent
from remaining groups.

So:
- reverse current group
- recursively process rest

This creates a clean divide-and-conquer structure.


Time Complexity:
O(n)

Each node is visited once.


Space Complexity:
O(n/k)

Recursive stack for groups.
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

Node* reverseInKgroups(Node* &head, int k){
    //base case
    if(head == NULL ) return head;
    
    Node* next = NULL; Node* curr = head; Node* prev = NULL;
    int count = 0;

    //reversing one group of k nodes
    while(curr!=NULL && count < k){
       next = curr->next;
       curr->next = prev;
       prev = curr;
       curr = next; 
       count++;
    }

    //recursively reverse K groups
    if(next != NULL){
        head->next = reverseInKgroups(next, k);
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

    head = reverseInKgroups(head, 3);
    cout<<"New Head at: "<<head->data<<endl;

    print(head);

}

/*
Mistakes I Made To Avoid:

1. Reversing incomplete groups
Wrong:
reverse even when nodes < k

Correct:
first count k nodes.


2. Forgetting reconnection
Important:
head->next = recursiveAnswer

Reason:
old head becomes tail after reversal.


3. Losing next pointer
Always store:
next = curr->next

before changing links.


4. Returning wrong pointer
Return:
prev

because prev becomes new head
of reversed group.


5. Confusing recursive structure
Each recursive call handles:
ONE group only.


6. Forgetting base case
if(head == NULL)
return head;


7. Thinking head remains same
After reversal:
head becomes tail of current group.



GOLDEN Interview Tips:

1. This problem combines:
- linked list reversal
- recursion
- pointer reconnection

Very important interview pattern.


2. Explain:
“Reverse current chunk,
recursively solve remaining list.”

This instantly shows understanding.


3. Always clarify:
“What happens when remaining nodes < k?”

Interviewers often check this edge case.


4. Draw one group separately first
before thinking about whole list.


5. Remember:
old head becomes new tail
after reversal.


6. Recursive solutions are elegant,
iterative solutions are more space optimized.


7. Most linked list problems are NOT hard logically.
They are pointer-management problems.
*/