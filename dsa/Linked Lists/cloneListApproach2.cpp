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
    PROBLEM:
    Create a deep copy of a linked list where each node
    contains:
    1. next pointer
    2. random pointer

    APPROACH (Optimized O(1) Space):

    STEP 1:
    Create clone list using next pointers only.

    Original:
    1 -> 2 -> 3

    Clone:
    1' -> 2' -> 3'

    STEP 2:
    Insert cloned nodes in between original nodes.

    1 -> 1' -> 2 -> 2' -> 3 -> 3'

    STEP 3:
    Copy random pointers.

    original->random->next gives cloned random node.

    STEP 4:
    Separate original and cloned lists.

    TIME COMPLEXITY: O(N)
    SPACE COMPLEXITY: O(1)
    */

void insertAtTail(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);

    // first node
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << "Data: " << temp->data;

        if(temp->random != NULL){
            cout << " , Random: " << temp->random->data;
        }
        else{
            cout << " , Random: NULL";
        }

        cout << endl;
        temp = temp->next;
    }

    cout << endl;
}

Node* copyList(Node* head){
    // edge case
    if(head == NULL){
        return NULL;
    }

    // STEP 1: Create clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while(temp != NULL){
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // STEP 2: Insert clone nodes in between original nodes
    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL){

        Node* next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    // STEP 3: Copy random pointers
    temp = head;

    while(temp != NULL){

        if(temp->random != NULL){
            temp->next->random = temp->random->next;
        }
        else{
            temp->next->random = NULL;
        }

        temp = temp->next->next;
    }

    // STEP 4: Revert changes and separate both lists
    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL){

        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;

        if(originalNode != NULL){
            cloneNode->next = originalNode->next;
        }

        cloneNode = cloneNode->next;
    }

    // STEP 5: Return cloned list
    return cloneHead;
}

int main(){

    /*
    Creating list:
    1 -> 2 -> 3 -> 4
    */

    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);

    // setting random pointers
    head->random = head->next->next;                  // 1 -> 3
    head->next->random = head;                        // 2 -> 1
    head->next->next->random = tail;                  // 3 -> 4
    tail->random = head->next;                        // 4 -> 2

    cout << "Original List:\n";
    print(head);

    Node* cloneHead = copyList(head);

    cout << "Cloned List:\n";
    print(cloneHead);

    return 0;
}

/*
MISTAKES TO AVOID:

1. Forgetting to initialize random pointer as NULL
   -> Causes garbage addresses and runtime errors.

2. Using cloneHead instead of cloneNode in loop conditions
   -> cloneHead never changes, leading to infinite loop.

3. Forgetting to move temp by temp->next->next
   -> Traversal breaks because clone nodes are inserted
      between original nodes.

4. Incorrect random pointer assignment
   WRONG:
   temp->next->random = temp->random

   CORRECT:
   temp->next->random = temp->random->next

   Why?
   temp->random gives original node.
   temp->random->next gives cloned node.

5. Forgetting NULL checks before accessing random
   -> Can cause segmentation fault.

6. Not separating original and cloned lists properly
   -> Original list structure gets corrupted.

7. Returning wrong head
   -> Return cloneHead, not head.


GOLDEN INTERVIEW TIPS:

1. Always explain WHY random copy works:
   cloned node of any original node is placed right after it.

2. Mention brute force first:
   Use hashmap <originalNode, cloneNode>.
   Time: O(N)
   Space: O(N)

3. Then optimize to O(1) space using interleaving technique.

4. Draw the structure while explaining:
   A -> A' -> B -> B'

5. Interviewers mainly check:
   - pointer handling
   - NULL safety
   - list restoration

6. This problem is famous for testing:
   - deep copy understanding
   - linked list manipulation
   - pointer confidence

7. If stuck during interview:
   First solve using hashmap.
   Then optimize later.
*/