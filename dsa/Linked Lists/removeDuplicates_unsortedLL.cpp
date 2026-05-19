#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM STATEMENT:
Given an unsorted linked list, remove duplicate nodes
such that each value appears only once.

Example:
10 -> 11 -> 14 -> 11 -> 13 -> 14 -> NULL

Output:
10 -> 11 -> 14 -> 13 -> NULL

APPROACH 1: Using HashMap / unordered_set (Optimal Time)

1. Traverse the linked list.
2. Store visited values inside unordered_set.
3. If current node already exists in set:
      - remove duplicate node
4. Else:
      - insert value into set
      - move forward normally

WHY THIS APPROACH?
- unordered_set gives O(1) average lookup.
- Best time complexity solution.
- Very common interview-preferred approach.

TIME COMPLEXITY:
O(N)

SPACE COMPLEXITY:
O(N)



APPROACH 2: Nested Traversal (Optimal Space)

1. Pick one node using curr.
2. Traverse remaining list using temp.
3. If duplicate found:
      - delete duplicate node
4. Continue until all duplicates removed.

WHY THIS APPROACH?
- No extra data structure used.
- Space optimized solution.

TIME COMPLEXITY:
O(N^2)

SPACE COMPLEXITY:
O(1)



APPROACH 3: Sort + Remove Duplicates

1. Sort the linked list.
2. Apply sorted duplicate-removal logic.

TIME COMPLEXITY:
O(N log N)

SPACE COMPLEXITY:
Depends on sorting method.
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

Node* uniqueUnsortedLinkedList(Node* &head){
    if(head == NULL) return head;

    /* Time complexity OPTIMAL (time: O(1) space:O(n))
    unordered_set<int> seen;

    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL){
        if(seen.count(curr->data)){
            prev->next = curr->next;
            Node* nodeToDelete = curr;
            curr = curr->next;
            delete nodeToDelete;
        }
        else{
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
    */

    /*Space Complexity OPTIMAL (space: O(1) time:O(n^2)*/
    Node* curr = head;
    
    while(curr != NULL){
        Node* prev = curr;
    Node* temp = curr->next;

    while(temp != NULL){

        // duplicate found
        if(curr->data == temp->data){

            prev->next = temp->next;

            Node* nodeToDelete = temp;
            temp = temp->next;
            nodeToDelete->next = NULL;
            delete nodeToDelete;
        }

        else{
            prev = temp;
            temp = temp->next;
        }
    }

    curr = curr->next;
    }

    /*Another approach is to sort the LinkedList first and then delete duplicates.
    here, Time: O(n log n) space: O(n)*/
}

void InsertAtTail(Node* &tail,int data){
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

    InsertAtTail(tail,12);
    InsertAtTail(tail,11);
    InsertAtTail(tail,13);
    InsertAtTail(tail,14);
    InsertAtTail(tail,12);
    InsertAtTail(tail,14);

    print(head);

    uniqueUnsortedLinkedList(head);
    cout<<"After removing duplicates: "<<endl;

    print(head);
}

/*
MISTAKES TO AVOID:

1. Destructor deleting remaining list
   Your destructor contains:
       delete next;

   So deleting one node may recursively delete
   the entire remaining linked list.

   Before deletion:
       nodeToDelete->next = NULL;

2. Forgetting to move temp before delete
   Wrong:
       delete temp;
       temp = temp->next;

   Correct:
       Node* nodeToDelete = temp;
       temp = temp->next;
       delete nodeToDelete;

3. Not updating prev correctly
   When duplicate is deleted:
       prev should NOT move forward.

4. Missing return statement
   Function declared:
       Node* uniqueUnsortedLinkedList(...)
   but nothing returned.

   Better:
       void uniqueUnsortedLinkedList(Node* &head)

5. Confusing optimal time vs optimal space
   HashMap approach:
       Best Time -> O(N)

   Nested loops:
       Best Space -> O(1)

GOLDEN INTERVIEW TIPS:

1. Always clarify:
   "Do you want optimal time or optimal space?"

2. Mention all three approaches briefly
   - HashMap
   - Nested loops
   - Sorting

3. In interviews:
   unordered_set approach is usually preferred first.

4. Carefully explain pointer handling during deletion.
   Most linked list bugs happen due to broken links.

5. Important deletion order:
       store next
       disconnect node
       delete node

6. Edge cases to mention:
   - empty list
   - single node
   - all duplicates
   - no duplicates

7. For unsorted LL:
   duplicates are NOT adjacent.
   This is why nested traversal or hashing is needed.
*/