#include <bits/stdc++.h>
using namespace std;

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

/*
PROBLEM STATEMENT:

Sort a singly linked list using Merge Sort.

Example:
Input:
4 -> 2 -> 1 -> 5 -> 3

Output:
1 -> 2 -> 3 -> 4 -> 5


APPROACH: Merge Sort on Linked List

STEP 1:
Find the middle of the linked list using slow-fast pointers.

STEP 2:
Break the list into two halves.

STEP 3:
Recursively sort both halves.

STEP 4:
Merge the two sorted linked lists.

WHY MERGE SORT?

- Works efficiently on linked lists.
- No need for extra shifting like arrays.
- Merge operation is very natural in linked lists.

HOW MERGING WORKS?

Compare nodes from both lists one by one:
- Smaller node gets attached first.
- Move forward in that list.
- Continue until one list finishes.
- Attach remaining nodes.


WHY IT WORKS?

Merge Sort follows Divide and Conquer:

1. Divide:
   Break list into smaller halves.

2. Conquer:
   Recursively sort each half.

3. Combine:
   Merge sorted halves into final sorted list.

Eventually every small list of size 1 becomes sorted automatically.


TIME COMPLEXITY:
O(N log N)

- log N levels of recursion
- O(N) merging work at each level

SPACE COMPLEXITY:
O(log N)

- Recursive stack space
*/

Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right){
    if(left == NULL) return right;
    if(right == NULL) return left;

    Node* answer = new Node(-1);
    Node* temp = answer;

    while(left != NULL && right != NULL){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left != NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right != NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }

    return answer->next;
}

Node* mergeSort(Node* head){
    //base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    //dividing into two halves
    Node* mid = findMid(head);

    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    //recursively sort  both halves
    left = mergeSort(left);
    right = mergeSort(right);

    //merge sorted halves into one linked list
    Node* result = merge(left, right);

    return result;
}

void insertAtTail(Node* &tail, int d){

    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node* head){

    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main(){

    /*
    Creating linked list:
    4 -> 2 -> 1 -> 5 -> 3
    */

    Node* node1 = new Node(4);

    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 5);
    insertAtTail(tail, 3);

    cout << "Original Linked List: ";
    print(head);

    head = mergeSort(head);

    cout << "Sorted Linked List: ";
    print(head);

    return 0;
}

/*
MISTAKES TO AVOID:

1. Forgetting to break the list
   mid->next = NULL is VERY important.

   Without this:
   - infinite recursion happens
   - list never gets divided properly

2. Wrong middle finding logic
   Starting fast incorrectly may create
   uneven partitions or recursion issues.

3. Forgetting base case
   if(head == NULL || head->next == NULL)

   Without this recursion never stops.

4. Losing nodes during merge
   Always move:
   - temp
   - left/right pointers carefully

5. Returning dummy node instead of dummy->next
   return answer->next is correct.

6. Creating new nodes unnecessarily
   Merge sort on linked list should rearrange pointers,
   not create fresh nodes for sorting.

7. Not handling NULL lists in merge()
   Always check:
   if(left == NULL)
   if(right == NULL)


GOLDEN INTERVIEW TIPS:

1. Merge Sort is the MOST IMPORTANT sorting algorithm
   for linked lists.

2. Quick Sort is generally avoided in linked lists because:
   - no random access
   - partitioning becomes expensive

3. Interviewers usually check:
   - middle finding
   - splitting
   - merging logic
   - pointer safety

4. Explain why Merge Sort is preferred:
   O(N log N) with efficient merging.

5. Draw recursion tree if interviewer seems confused.

6. Always mention:
   Arrays use extra space during merge,
   but linked lists can merge using pointers directly.

7. Common follow-up:
   "Can you do it iteratively?"
   -> Bottom-up merge sort approach.

8. Most bugs happen in:
   - splitting the list
   - merge pointer movement
*/