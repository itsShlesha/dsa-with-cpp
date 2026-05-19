#include <iostream>
using namespace std;

/*
PROBLEM STATEMENT:
Given a linked list, detect whether a cycle/loop exists.
If a cycle is present:
1. Find the starting node of the cycle.
2. Remove the loop without losing any nodes.

APPROACH:
We use Floyd’s Cycle Detection Algorithm (Tortoise & Hare).

1. Detect Cycle
   - Use two pointers:
     slow -> moves 1 step
     fast -> moves 2 steps
   - If they meet, a cycle exists.

2. Find Start of Cycle
   - Keep one pointer at head.
   - Keep second pointer at intersection point.
   - Move both one step at a time.
   - The node where they meet again is the start of cycle.

3. Remove Loop
   - Traverse from startOfCycle node until:
       temp->next == startOfCycle
   - Break the loop:
       temp->next = NULL

WHY THIS APPROACH?
- Floyd’s algorithm is optimal.
- Detects cycle in O(N) time.
- Uses constant extra space.
- Better than using map/set because those require O(N) space.

TIME COMPLEXITY:
- Detect Cycle: O(N)
- Find Start Node: O(N)
- Remove Loop: O(N)

Overall: O(N)

SPACE COMPLEXITY:
O(1)
No extra data structures used.
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

Node* detectCycle(Node* &head){

    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cout<<"Cycle present at "<<slow->data<<endl;
            return slow;
        }
    }

    return NULL;
}

Node* startOfCycle(Node* &head){

    if(head == NULL) return NULL;

    Node* intersection = detectCycle(head);

    if(intersection == NULL) return NULL;

    Node* slow = head;

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

void removeLoop(Node* &head){

    if(head == NULL) return;

    Node* startOfCycleNode = startOfCycle(head);

    if(startOfCycleNode == NULL) return;

    Node* temp = startOfCycleNode;

    while(temp->next != startOfCycleNode){
        temp = temp->next;
    }

    temp->next = NULL;
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

    InsertAtTail(tail, 12);
    InsertAtTail(tail, 13);
    InsertAtTail(tail, 4);

    // creating cycle
    tail->next = head->next;

    if(detectCycle(head)){

        Node* startOfCycleNode = startOfCycle(head);

        cout<<"Start of Cycle is at: "<<startOfCycleNode->data<<endl;

        cout<<"Removing Loop"<<endl;

        removeLoop(head);

        print(head);
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }
}

/*
MISTAKES TO AVOID:

1. Printing pointer instead of data
   Wrong:
       cout << startOfCycleNode->next;
   Correct:
       cout << startOfCycleNode->data;

2. Forgetting NULL checks
   Always check:
       if(intersection == NULL)
   before traversing further.

3. Returning Node* but not returning anything
   If function does not return a node:
       use void

4. Dangerous destructor recursion
   This:
       delete next;
   can crash if a cycle exists.
   Avoid recursive delete in cyclic linked lists.

5. Using special characters in file names
   Avoid:
       detect&removeLoop.cpp
   Use:
       detect_removeLoop.cpp

GOLDEN INTERVIEW TIPS:

1. Always explain WHY Floyd works
   Interviewers love intuition more than memorized code.

2. Mention fast and slow pointer movement clearly
   slow = 1 step
   fast = 2 steps

3. State edge cases before coding
   - empty list
   - single node
   - no cycle
   - cycle at head

4. Best order to explain:
   Detect -> Find Start -> Remove Loop

5. Remember:
   Meeting point is NOT always start of cycle.

6. If asked alternative approach:
   Use map/unordered_map
   but mention:
       Time: O(N)
       Space: O(N)

7. While removing loop:
   stop at node BEFORE start node
   then set:
       temp->next = NULL
*/