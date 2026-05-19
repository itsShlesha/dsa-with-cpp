#include <iostream>
using namespace std;

/*
PROBLEM STATEMENT:
Given a sorted linked list, remove all duplicate nodes
such that each element appears only once.

Example:
10 -> 11 -> 11 -> 13 -> 14 -> 14 -> NULL

Output:
10 -> 11 -> 13 -> 14 -> NULL

APPROACH:
Since the linked list is sorted, duplicate nodes will always
be adjacent.

1. Start from head using pointer curr.
2. Compare current node with next node.
3. If both values are same:
      - store duplicate node
      - connect current node to next distinct node
      - delete duplicate node
4. Else move curr forward.
5. Continue until end of list.

WHY THIS APPROACH?
- Sorting guarantees duplicates are together.
- We only need one traversal.
- No extra data structure needed.
- Efficient in both time and space.

TIME COMPLEXITY:
O(N)
Each node is visited once.

SPACE COMPLEXITY:
O(1)
No extra memory used.
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

Node* uniqueSortedLinkedList(Node* &head){
    if(head == NULL) return head;

    Node* curr = head;
    while(curr != NULL && curr->next != NULL){
        if(curr->data == curr->next->data){ 
            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;
            nodeToDelete->next = NULL;
            delete nodeToDelete;
            curr->next = next_next;
        }
        else curr = curr->next;
    }

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
    InsertAtTail(tail,11);
    InsertAtTail(tail,13);
    InsertAtTail(tail,14);
    InsertAtTail(tail,14);
    InsertAtTail(tail,14);

    print(head);

    uniqueSortedLinkedList(head);
    cout<<"After removing duplicates: "<<endl;

    print(head);
}

/*
MISTAKES TO AVOID:

1. Wrong order of conditions
   Wrong:
       curr->data == curr->next->data && curr->next != NULL

   Correct:
       curr->next != NULL && curr->data == curr->next->data

   Always check NULL first before accessing data.

2. Destructor causing recursive deletion
   Your destructor contains:
       delete next;

   So deleting one node may delete the entire remaining list.

   Before deleting:
       nodeToDelete->next = NULL;

3. Infinite loop possibility
   If duplicate is removed,
   do NOT move curr forward immediately.
   Recheck current node again because multiple duplicates may exist.

4. Returning head unnecessarily
   Since head is passed by reference:
       void function(Node* &head)
   is cleaner than returning head.

GOLDEN INTERVIEW TIPS:

1. Mention why sorting helps
   Since list is sorted,
   duplicates are adjacent.
   This is the key observation.

2. State brute force alternative
   Using map/set:
       Time: O(N)
       Space: O(N)

   Then explain why current approach is better.

3. Carefully explain pointer updates
   Interviewers check whether you lose links accidentally.

4. Always discuss edge cases
   - empty list
   - single node
   - all duplicates
   - no duplicates

5. Important deletion sequence:
       store next
       disconnect node
       delete node
       reconnect list

6. Never access:
       curr->next->data
   before checking:
       curr->next != NULL
*/