#include <iostream>
using namespace std;

/*
Problem Statement:
Detect whether a linked list contains a cycle.

A cycle exists if some node points back
to a previous node instead of NULL.

Example:
1 -> 2 -> 3 -> 4
          ^    |
          |____|

Output:
true


Approach:
Use Floyd’s Cycle Detection Algorithm
(Tortoise and Hare Algorithm).

Two pointers:
1. slow -> moves 1 step
2. fast -> moves 2 steps

If cycle exists:
fast and slow will eventually meet.

If no cycle:
fast reaches NULL.


Why This Approach?
If two pointers move at different speeds
inside a cycle,
the faster pointer eventually catches
the slower pointer.

This avoids:
- extra arrays
- hashing
- extra memory

Optimal cycle detection technique.


Time Complexity:
O(n)

Space Complexity:
O(1)
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

bool isCircular(Node* &head){
    if(head == NULL) return false;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast) return true;
    }

    return false;
}

void InsertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    InsertAtTail(tail, 12);
    InsertAtTail(tail, 13);
    InsertAtTail(tail, 4);
    
    //creating a cycle
    tail->next = head->next;

    if(isCircular(head)){
        cout << "Cycle is present" << endl;
    }
    else{
        cout << "Cycle is not present" << endl;
    }
}

/*
Mistakes I Made To Avoid:

1. Wrong loop condition
Wrong:
fast->next == NULL

Correct:
fast->next != NULL

Reason:
Need valid next node for double jump.


2. Returning wrong datatype
Function returns bool,
not Node*.


3. Starting fast at head->next unnecessarily
Cleaner:
slow = head
fast = head


4. Forgetting NULL checks
Always check:
fast != NULL && fast->next != NULL

before:
fast = fast->next->next


5. Confusing circular LL and cycle detection
This problem detects ANY cycle,
not necessarily fully circular list.


6. Infinite traversal risk
Never use normal print function
on cyclic linked list.


7. Forgetting how meeting occurs
Fast moves 2x speed,
so gap reduces inside cycle.



GOLDEN Interview Tips:

1. Floyd’s Algorithm is one of the MOST important
linked list patterns.


2. Always explain:
“Fast pointer eventually catches slow pointer.”


3. This same pattern is reused in:
- finding cycle start
- happy number
- duplicate number problems


4. Mention:
“No extra space required.”

Important optimization point.


5. Draw cycle visually during interviews.
Pointer movement becomes very intuitive.


6. The meeting point is NOT necessarily
the start of cycle.


7. Linked list interview problems are mostly:
- traversal
- pointer movement
- reconnection logic
*/