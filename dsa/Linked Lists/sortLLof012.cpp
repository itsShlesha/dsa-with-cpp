#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM STATEMENT:
Sort a linked list containing only 0s, 1s, and 2s.

Example:
0 -> 1 -> 2 -> 0 -> 0 -> NULL

Output:
0 -> 0 -> 0 -> 1 -> 2 -> NULL


APPROACH 1: DATA REPLACEMENT APPROACH

Step 1:
Traverse the linked list and count:
- number of 0s
- number of 1s
- number of 2s

Step 2:
Traverse the list again and overwrite node values:
- first place all 0s
- then all 1s
- then all 2s

Example:
Original:
0 -> 1 -> 2 -> 0 -> 0

Counts:
0s = 3
1s = 1
2s = 1

After replacement:
0 -> 0 -> 0 -> 1 -> 2


WHY THIS WORKS:
The linked list only contains 3 possible values.
So counting frequency and rewriting values
automatically gives sorted order.


TIME COMPLEXITY:
O(N)
Two traversals.


SPACE COMPLEXITY:
O(1)



APPROACH 2: LINK REPLACEMENT APPROACH

Create 3 separate linked lists:
- zero list
- one list
- two list

Traverse original list:
- attach each node to its respective list

Finally connect:
0 list -> 1 list -> 2 list

Example:

Original:
0 -> 1 -> 2 -> 0 -> 0

Zero list:
0 -> 0 -> 0

One list:
1

Two list:
2

After merging:
0 -> 0 -> 0 -> 1 -> 2


WHY THIS WORKS:
Each node is grouped according to its value.

Since nodes are rearranged directly:
- no data modification is needed
- original nodes are reused

This is generally preferred in interviews
because pointer manipulation is tested.


TIME COMPLEXITY:
O(N)
Single traversal.


SPACE COMPLEXITY:
O(1)
Only dummy nodes are used.
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

void InsertAtTail(Node* &tail, Node* &curr){
    tail->next = curr;
    tail = curr;
}

Node* sortList(Node* &head){
    /*Data Replacement Approach: 
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while(temp != NULL){
        if (temp->data == 0) zeroCount++;
        else if (temp->data == 1) oneCount++;
        else twoCount++;

        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        if(zeroCount != 0){
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount != 0){
            temp->data = 1;
            oneCount--;
        }
        else if(twoCount != 0){
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
    return head;
    */

    //Link Replacement Approach
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    while(curr != NULL){
        Node* nextNode = curr->next;
        curr->next = NULL;

        int value = curr->data;

        if(value == 0){
            InsertAtTail(zeroTail, curr);
        }
        else if(value == 1){
            InsertAtTail(oneTail, curr);
        }
        else if(value == 2){
            InsertAtTail(twoTail, curr);
        }

        curr = nextNode;
    }

    if(oneHead->next != NULL) zeroTail->next = oneHead->next;
    else zeroTail->next = twoHead->next;

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;

    zeroHead->next = NULL;
    oneHead->next = NULL;
    twoHead->next = NULL;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

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
    Node* node1 = new Node(0);
    Node* head = node1;
    Node* tail = node1;

    InsertAtTail(tail, 1);
    InsertAtTail(tail, 2);
    InsertAtTail(tail, 0);
    InsertAtTail(tail, 0);
    print(head);

    sortList(head);
    cout<<"After sorting the list: "<<endl;
    print(head);
}

/*
MISTAKES TO AVOID:

1. Forgetting:
      curr = curr->next;
   -> infinite loop

2. Not storing nextNode before breaking links
   -> remaining list gets lost

3. Forgetting:
      curr->next = NULL;
   -> can create cycles

4. Directly deleting dummy nodes when destructor
   recursively deletes next nodes
   -> entire list gets deleted accidentally

5. Forgetting:
      twoTail->next = NULL;
   -> garbage links may remain


GOLDEN INTERVIEW TIPS:

1. DATA replacement is easier to code.
   LINK replacement is more interview-preferred.

2. If node structure contains more fields:
   NEVER change data unnecessarily.

3. Dummy nodes simplify insertion logic greatly.

4. In linked lists:
   Always save next pointer BEFORE changing links.

5. Whenever debugging linked lists:
   draw connections after every pointer update.
*/