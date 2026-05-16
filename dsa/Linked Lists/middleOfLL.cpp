#include <iostream>
using namespace std;

/*
Problem Statement:
Find the middle node of a singly linked list.

If the list has even number of nodes,
return the second middle node.

Example:
Input:
1 -> 2 -> 3 -> 4 -> 5

Output:
3

Example:
Input:
1 -> 2 -> 3 -> 4 -> 5 -> 6

Output:
4


Approach:
Use two pointers:
1. slow -> moves one step
2. fast -> moves two steps

While fast traverses the list quickly,
slow moves at half the speed.

When fast reaches the end,
slow automatically reaches the middle.


Why This Approach?
Instead of counting nodes separately,
we find the middle in a single traversal.

This is the optimal linked list technique:
- no extra space
- no second traversal
- very interview common pattern


Time Complexity:
O(n)

Each node is visited at most once.


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

Node* MiddleNode(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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

    Node* middleNode = MiddleNode(head);
    cout<<"Middle Node at: "<<middleNode->data<<endl;
}

/*
Mistakes I Made To Avoid:

1. Wrong loop condition
Wrong:
while(fast != NULL)

Reason:
fast->next may become NULL,
causing segmentation fault on:
fast->next->next


Correct:
while(fast != NULL && fast->next != NULL)


2. Starting fast incorrectly
Current code:
fast = head->next

This returns:
- first middle in even length list

LeetCode 876 expects:
- second middle

Correct:
fast = head


3. Forgetting edge cases
Handle:
- empty list
- single node list


4. Accessing NULL pointer
Always check:
fast != NULL

before:
fast->next


5. Confusing middle definition
Different questions may ask:
- first middle
- second middle

Always read carefully.



GOLDEN Interview Tips:

1. Fast & slow pointer is one of the MOST important
linked list patterns.


2. Remember:
fast moves 2x speed of slow.

This is the core intuition.


3. Starting positions matter
fast = head
and
fast = head->next

can change final answer.


4. This pattern is reused in:
- cycle detection
- palindrome linked list
- merge sort on linked list
- finding loop start


5. Always say:
“One traversal solution.”

Interviewers love optimized traversal logic.


6. Draw pointer movement manually
for odd and even length lists.


7. Never write:
fast->next->next

without checking:
fast != NULL && fast->next != NULL
*/