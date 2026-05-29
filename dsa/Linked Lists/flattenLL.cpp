#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* child;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> child = NULL;
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

Given a linked list where:
- next pointer points to the right
- child pointer points downward

Each child list is individually sorted.

Flatten the entire linked list into a single
sorted linked list using child pointers only.


APPROACH: Recursive Merge Technique

MAIN IDEA:

1. Flatten the right side recursively.
2. Merge current vertical list with flattened right list.
3. Return merged list.

This works exactly like Merge Sort merging.


STEP-BY-STEP:

Suppose:

5 -> 10 -> 19

We recursively flatten:
flatten(19)

Then:
merge(10 list, flattened 19 list)

Then:
merge(5 list, flattened result)

Eventually entire structure becomes sorted.


WHY IT WORKS?

Each vertical list is already sorted.

Recursion ensures:
- right side becomes fully flattened and sorted

Then merging two sorted lists produces:
- one larger sorted list

Repeated merging gives final sorted chain.


IMPORTANT OBSERVATION:

Final flattened list uses ONLY child pointers.

next pointers are removed completely.


TIME COMPLEXITY:
O(N * M)

More accurately:
Each node participates in merge operations.

For total nodes K:
Time Complexity = O(K)

SPACE COMPLEXITY:
O(K)

Recursive stack space due to merge + flatten recursion.
*/

Node* merge(Node* a, Node* b){

    // if one list becomes empty
    if(a == NULL) return b;
    if(b == NULL) return a;

    Node* result;

    // choose smaller node first
    if(a->data < b->data){
        result = a;
        result->child = merge(a->child, b);
    }
    else{
        result = b;
        result->child = merge(a, b->child);
    }

    // remove old next links
    result->next = NULL;

    return result;
}

Node* flatten(Node* head){

    // base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    // recursively flatten right side
    Node* right = flatten(head->next);

    // disconnect next pointer
    head->next = NULL;

    // merge current list with flattened right list
    Node* result = merge(head, right);

    return result;
}

void print(Node* head){

    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->child;
    }

    cout << endl;
}

int main(){

    /*
    Creating multilevel linked list:

    5 -> 10 -> 19 -> 28
    |     |      |      |
    7     20     22     35
    |            |      |
    8            50     40
    |                   |
    30                  45
    */

    Node* head = new Node(5);

    head->child = new Node(7);
    head->child->child = new Node(8);
    head->child->child->child = new Node(30);

    head->next = new Node(10);
    head->next->child = new Node(20);

    head->next->next = new Node(19);
    head->next->next->child = new Node(22);
    head->next->next->child->child = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->child = new Node(35);
    head->next->next->next->child->child = new Node(40);
    head->next->next->next->child->child->child = new Node(45);

    cout << "Flattened Linked List:\n";

    Node* ans = flatten(head);

    print(ans);

    return 0;
}

/*
MISTAKES TO AVOID:

1. Forgetting to declare child pointer
   -> Compilation error occurs immediately.

2. Calling:
   flatten(head)

   instead of:
   flatten(head->next)

   -> Causes infinite recursion.

3. Forgetting:
   result->next = NULL

   -> Old horizontal links remain.
   -> Flattened structure becomes corrupted.

4. Traversing using next instead of child
   after flattening.

   Final list uses ONLY child pointers.

5. Not handling NULL cases in merge()
   -> Segmentation faults happen easily.

6. Mixing next and child pointers during merge
   -> Logic breaks completely.

7. Forgetting base case
   if(head == NULL || head->next == NULL)

   -> Recursion never stops.


GOLDEN INTERVIEW TIPS:

1. This problem is basically:
   "Merge K Sorted Linked Lists"

2. Mention similarity with Merge Sort:
   - divide recursively
   - merge sorted lists

3. Interviewers mainly test:
   - recursion understanding
   - pointer manipulation
   - linked list merging

4. Most important explanation:
   "Right side is flattened first,
   then current list is merged."

5. Always clarify:
   Final answer uses child pointers only.

6. Common follow-up:
   "Can we use priority queue?"
   YES.
   Min Heap approach:
   Time: O(K log N)

7. Recursive merge solution is cleaner
   and usually expected in interviews.

8. Dry run one merge manually during interview.
   It makes the recursion much easier to explain.
*/