#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }

    ~Node(){
        int value = this->data;

        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }

        cout << "Memory is free for node with data "
             << value << endl;
    }
};

/*
PROBLEM STATEMENT:
Given a linked list where each node contains:
1. next pointer
2. random pointer (can point to any node or NULL)

Create a deep copy of the linked list.

A deep copy means:
- New nodes should be created
- next and random structure should remain same
- Original and copied lists should be completely independent

--------------------------------------------------

APPROACH: HashMap Mapping Technique

STEP 1:
Create a separate cloned linked list using only next pointers.

STEP 2:
Store mapping:
original node -> cloned node

using unordered_map<Node*, Node*>.

STEP 3:
Traverse both lists together and copy random pointers:
cloneNode->random = map[originalNode->random]

--------------------------------------------------

WHY IT WORKS:
The hashmap directly tells us which cloned node corresponds
to an original node.

So whenever original random points somewhere,
we can instantly connect clone random to the cloned version
of that target node.

--------------------------------------------------

TIME COMPLEXITY:
O(N)
- Creating clone list = O(N)
- Creating map = O(N)
- Copying random pointers = O(N)

SPACE COMPLEXITY:
O(N)
- Extra hashmap used
*/

void insertAtTail(Node* &head, Node* &tail, int d){
    Node* newNode = new Node(d);

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

Node* copyList(Node* head){

    // STEP 1: Create clone list using next pointers
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while(temp != NULL){
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // STEP 2: Create mapping from original node -> cloned node
    unordered_map<Node*, Node*> oldToNewNode;

    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL){
        oldToNewNode[originalNode] = cloneNode;

        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    // STEP 3: Copy random pointers
    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL){

        if(originalNode->random != NULL){
            cloneNode->random = oldToNewNode[originalNode->random];
        }
        else{
            cloneNode->random = NULL;
        }

        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
}

void printList(Node* head){

    while(head != NULL){

        cout << "Data: " << head->data;

        if(head->random != NULL){
            cout << ", Random: " << head->random->data;
        }
        else{
            cout << ", Random: NULL";
        }

        cout << endl;

        head = head->next;
    }
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);

    // setting random pointers
    head->random = tail;                 // 1 -> 4
    head->next->random = head;           // 2 -> 1
    head->next->next->random = tail;    // 3 -> 4
    tail->random = head->next;          // 4 -> 2

    cout << "Original List:\n";
    printList(head);

    Node* cloneHead = copyList(head);

    cout << "\nCloned List:\n";
    printList(cloneHead);

    return 0;
}

/*
MISTAKES TO AVOID:

1. Forgetting to declare random pointer inside class
   Node* random;

2. Missing semicolon after:
   this->random = NULL;

3. Forgetting NULL check before:
   originalNode->random

4. Accidentally linking clone random to ORIGINAL node
   instead of cloned node.

5. Not advancing both originalNode and cloneNode together.

6. Returning original head instead of cloneHead.

--------------------------------------------------

GOLDEN INTERVIEW TIPS:

1. Mention that this is a DEEP COPY problem.

2. Explain difference:
   Shallow Copy:
   copies addresses

   Deep Copy:
   creates entirely new nodes

3. First explain hashmap approach clearly.
   It is easier and interviewer-friendly.

4. Then mention optimized O(1) space approach
   using node insertion technique if asked.

5. Always dry run random pointer cases:
   - random = NULL
   - self pointing random
   - backward random
   - forward random
*/